#include "fileSynchronization.hpp"

void scan(const fs::path& dir_path, FileContainer fileContainer) {

    for (auto const& dir_entry : std::filesystem::recursive_directory_iterator{dir_path}) 
    {
        if(dir_entry.is_regular_file()) {
            std::string fileName = dir_entry.path().filename();
            const auto& filePath = dir_entry.path();
            const auto& fileModificationTime = dir_entry.last_write_time();

            FileInfo fileInfo(fileName, filePath, fileModificationTime, )
            allFileInfo.emplace_back(fileName, filePath, fileModificationTime, FileStatus::newFile);
        }
    }
}