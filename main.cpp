#include <algorithm>
#include <iostream>
#include <string>
#include <filesystem>
#include "fileInfo.hpp"
#include "fileContainer.hpp" 
#include "fileSynchronization.hpp"

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
    scan(syncDirectoriesPath, allFiles, syncFolders);
    // allFiles.print();
    sync(syncDirectoriesPath, allFiles, syncFolders);
    printSyncDirectories(syncFolders);

    // bool b = syncFolders[0].contains("file3");
    return 0;
}



