#pragma once

#include <algorithm>
#include <vector>
#include "fileInfo.hpp"

namespace fs = std::filesystem;

class Folder
{
public:
    Folder(fs::path folderPath);

    std::vector<FileInfo>::const_iterator contains(const std::string fileName) const;
    fs::path folderPath_;    
    std::vector<FileInfo> files;    
};
