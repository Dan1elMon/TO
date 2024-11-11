#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cmath>
#include <thread>
#include <mutex>
#include <unordered_map>
//#include <set>

struct Rating {
    int userId;
    int movieId;
    float rating;
    int time;
};

// Vectores y estructuras globales para almacenar datos y resultados
std::vector<Rating> ratings;
std::vector<std::pair<std::pair<int, int>, std::pair<double, double>>> distances;
std::mutex mtx;

// Función para leer el archivo CSV y cargar los datos
void loadCSV(const std::string &filename) {
    std::ifstream file(filename);
    std::string line;
    int lineCount = 0;

    while (std::getline(file, line)) {
        std::istringstream ss(line);
        std::string token;
        Rating r;

        std::getline(ss, token, ',');
        r.userId = std::stoi(token);

        std::getline(ss, token, ',');
        r.movieId = std::stoi(token);

        std::getline(ss, token, ',');
        r.rating = std::stof(token);

        std::getline(ss, token, ',');
        r.time = std::stoi(token);

        ratings.push_back(r);
        lineCount++;
    }
    std::cout << "Total de líneas cargadas: " << lineCount << std::endl;
}

// Función para calcular distancias entre pares de productos calificados por el mismo usuario
void calculateDistances(const std::unordered_map<int, std::vector<Rating>> &userRatings, int start, int end) {
    int localCount = 0;

    for (auto it = userRatings.begin(); std::distance(userRatings.begin(), it) < end; ++it) {
        if (std::distance(userRatings.begin(), it) < start) continue;

        const auto &userRatings = it->second;

        for (size_t i = 0; i < userRatings.size(); ++i) {
            for (size_t j = i + 1; j < userRatings.size(); ++j) {
                int product1 = userRatings[i].movieId;
                int product2 = userRatings[j].movieId;
                double manhattanDistance = std::abs(userRatings[i].rating - userRatings[j].rating);
                double euclideanDistance = std::pow(userRatings[i].rating - userRatings[j].rating, 2);

                std::lock_guard<std::mutex> lock(mtx);
                distances.push_back({{product1, product2}, {manhattanDistance, std::sqrt(euclideanDistance)}});
                localCount++;
            }
        }
    }

    std::lock_guard<std::mutex> lock(mtx);
    std::cout << "Distancias calculadas por hilo: " << localCount << std::endl;
}

// Función principal para configurar y ejecutar los hilos
int main() {
    std::string filename = "C:/Users/USER/Desktop/WS/Universidad/2024-B/TO/Lab06/EjerciciosPropuestos/ej92Propuesto/ej02Propuesto/ratings_s.csv";
    loadCSV(filename);

    // Organizar calificaciones por usuario
    std::unordered_map<int, std::vector<Rating>> userRatings;
    for (const auto &rating : ratings) {
        userRatings[rating.userId].push_back(rating);
    }

    // Definir el número de hilos y dividir el trabajo
    int numThreads = 4;
    std::vector<std::thread> threads;
    int batchSize = userRatings.size() / numThreads;

    //auto it = userRatings.begin();
    for (int i = 0; i < numThreads; ++i) {
        int start = i * batchSize;
        int end = (i == numThreads - 1) ? userRatings.size() : (i + 1) * batchSize;
        threads.emplace_back(calculateDistances, std::cref(userRatings), start, end);
    }

    // Esperar a que terminen todos los hilos
    for (auto &t : threads) {
        t.join();
    }

    // Imprimir los primeros 5 resultados
    for (int i = 0; i < 5 && i < distances.size(); ++i) {
        auto &pair = distances[i];
        std::cout << " Producto " << pair.first.second << ": "
                  << "Manhattan = " << pair.second.first
                  << ", Euclidea = " << pair.second.second << "\n";
    }

    return 0;
    //asd
}
