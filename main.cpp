#include <algorithm>
#include <iostream>
#include <string>
#include <filesystem>
#include "fileInfo.hpp"

namespace fs = std::filesystem;

void filesVector(const fs::path& dir_path, std::vector<fs::path>& files);
void printAllFiles(const std::vector<fs::path>& files);

int main() {
    fs::path syncDirectoriesPath {fs::current_path().parent_path() / "DirForSync"};
    std::cout << syncDirectoriesPath << '\n';
    std::vector<fs::path> files;
    std::vector<fileInfo> fileInfo
    filesVector(syncDirectoriesPath, files);
    printAllFiles(files);

    return 0;
}

void filesVector(const fs::path& dir_path, std::vector<fs::path>& files) {
    std::copy_if(fs::recursive_directory_iterator(dir_path), {}, std::back_insert_iterator(files), [](const auto& entry){ 
        return entry.is_regular_file(); });
}

void printAllFiles(const std::vector<fs::path>& files) {
   for(const auto& filePath : files) {
        std::cout << filePath << '\n';
   } 
}
