#pragma once

#include <vector>
#include "fileInfo.hpp"

class FileContainer {
public:
    FileContainer();
    void print();
    void add(FileInfo fileInfo);   
    // bool contains(std::string fileName); // check whether container contains file 
    std::vector<FileInfo> container_;
};
