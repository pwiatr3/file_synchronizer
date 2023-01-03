#include <algorithm>
#include <iostream>
#include <string>
#include <filesystem>
#include "fileInfo.hpp"
#include "fileContainer.hpp"

namespace fs = std::filesystem;

void scan(const fs::path& dir_path, std::vector<FileInfo>& allFileInfo);

int main() {
    // fs::path syncDirectoriesPath {fs::current_path() / "DirForSync"};
    fs::path syncDirectoriesPath {fs::current_path().parent_path() / "DirForSync"};
    FileContainer fileContainer;
    
    std::cout << "Sync directory path: " << syncDirectoriesPath << '\n';
    // scan(syncDirectoriesPath, allFilesInfo);

    return 0;
}



