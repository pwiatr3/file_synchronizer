#pragma once

#include <iostream>
#include <string>
#include <filesystem>
#include <chrono>

namespace fs = std::filesystem;

enum class FileStatus {
    newFile,
    updatedFile,
    deletedFile
};

class FileInfo {
public:
    FileInfo(std::string fileName, fs::path sourceDirPath, fs::file_time_type modificationTime,FileStatus status): fileName_(fileName),
        sourceDirectoryPath_(sourceDirPath),
        modificationTime_(modificationTime)
     {}
    friend std::ostream& operator<<(std::ostream& os, const FileInfo& fileInfo);
// private:
    std::string fileName_;
    fs::path sourceDirectoryPath_;
    fs::file_time_type modificationTime_;
};

std::string file_time_to_string(std::filesystem::file_time_type const& ftime);