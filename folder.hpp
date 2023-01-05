#pragma once
#include <vector>
#include "fileInfo.hpp"

namespace fs = std::filesystem;

struct Folder
{
    Folder(fs::path folderPath);
    bool contains(const std::string fileName);
    fs::path folderPath_;    
    std::vector<FileInfo> files;    
};
