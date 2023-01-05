#include "fileContainer.hpp"
#include <algorithm>

FileContainer::FileContainer() {}

void FileContainer::print() {
    for(const auto& fileInfo : container_) {
        std::cout << fileInfo << '\n';
    }     
}

void FileContainer::add(FileInfo fileInfo) {
    auto it = std::find_if(begin(container_), end(container_), [fileInfo](FileInfo& fI){ 
            return fI.fileName_ == fileInfo.fileName_; 
    });
    // check if file of that name was found
    if(it != end(container_)) {
            // if found 
            if(fileInfo.modificationTime_ > it->modificationTime_) {
                *it = fileInfo; // replace file from container to most recent file of the same name
            }
    }
    else { 
        container_.push_back(fileInfo);
    }

}

// bool contains(std::string fileName) {
//     auto it = std::find_if(begin(container_), end(container_), [fileInfo](FileInfo& fI){ 
//             return fI.fileName_ == fileInfo.fileName_; 
//     });
//     return it != end(container);    
// }

