#include "FileManager.h"
#include <fstream>
#include <iostream>

std::vector<std::string> FileManager::readFile(const std::string& filePath) {
    std::vector<std::string> data;
    std::ifstream inputFile(filePath);
    if (inputFile.is_open()) {
        std::string line;
        while (std::getline(inputFile, line)) {
            data.push_back(line);
        }
        inputFile.close();
    } else {
        std::cerr << "Error al abrir el archivo para lectura." << std::endl;
    }
    return data;
}

void FileManager::writeFile(const std::string& filePath, const std::string& data) {
    std::ofstream outputFile(filePath);
    if (outputFile.is_open()) {
        outputFile << data;
        outputFile.close();
    } else {
        std::cerr << "Error al abrir el archivo para escritura." << std::endl;
    }
}
