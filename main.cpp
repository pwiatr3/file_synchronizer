#include <algorithm>
#include <iostream>
#include <string>
#include <filesystem>
#include "fileInfo.hpp"
#include "fileContainer.hpp" 
#include "fileSynchronization.hpp"
#include "SHA256.hpp"
#include "fileCheckSum.hpp"

namespace fs = std::filesystem;

int main() {

    #if (RELEASE) 
        fs::path syncDirectoriesPath {fs::current_path().parent_path() / "DirForSync"};
    #else
        fs::path syncDirectoriesPath {"DirForSync"};
    #endif

    FileContainer allFiles;
    std::vector<Folder> syncFolders;
   
    std::cout << "Sync directory path: " << syncDirectoriesPath << '\n';
    // scan(syncDirectoriesPath, allFiles, syncFolders);
    // // allFiles.print();
    // sync(syncDirectoriesPath, allFiles, syncFolders);
    // printSyncDirectories(syncFolders);
    
    fs::path path{"/home/pawel/Desktop/pawel/adamski/file_synchronizer/DirForSync/F1/file1"};
    std::string content = readFile(path);
    std::cout << content << '\n';
    SHA256 sha;
    sha.update(content);
    std::string checkSum = sha.digest();
    std::cout << checkSum << std::endl;
    

    return 0;
}



