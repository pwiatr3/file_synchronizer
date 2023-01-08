#pragma once

#include <vector>
#include "fileInfo.hpp"

class FileContainer {
public:
    FileContainer();
    void print();
    void add(FileInfo fileInfo);   
    std::vector<FileInfo> container_;
};
