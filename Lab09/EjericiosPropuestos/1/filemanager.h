#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <string>
#include <vector>

class FileManager {
public:
    static std::vector<std::string> readFile(const std::string& filePath);
    static void writeFile(const std::string& filePath, const std::string& data);
};

#endif // FILEMANAGER_H
