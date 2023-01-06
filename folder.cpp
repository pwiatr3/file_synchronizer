#include "folder.hpp"


Folder::Folder(fs::path folderPath): folderPath_(folderPath)  {}
/*
* Function returns iterator to the file, if file doesn't exist
* then returns iterator to the end of container
*/
std::vector<FileInfo>::const_iterator Folder::contains(const std::string fileName) const {
    auto it = std::find_if(begin(files), end(files), [fileName](const FileInfo& fI){ 
            return fI.fileName_ == fileName; 
    });
    return it; 
}