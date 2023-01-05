#include "folder.hpp"


Folder::Folder(fs::path folderPath): folderPath_(folderPath)  {}
bool Folder::contains(const std::string fileName) {
    auto it = std::find_if(begin(files), end(files), [fileName](FileInfo& fI){ 
            return fI.fileName_ == fileName; 
    });
    return it != end(files);    
}