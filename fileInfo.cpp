#include "fileInfo.hpp"


std::ostream& operator<<(std::ostream& os, const FileInfo& fileInfo) {
    os << fileInfo.fileName_ << ' ' << fileInfo.sourceDirectoryPath_ << " mod time: " << file_time_to_string(fileInfo.modificationTime_) << '\n';
    return os;
}

bool operator==(const FileInfo& lhs, const FileInfo& rhs) {
    return (lhs.fileName_ == rhs.fileName_ && lhs.modificationTime_ == rhs.modificationTime_ &&
                lhs.sourceDirectoryPath_ == rhs.sourceDirectoryPath_);
}

std::string file_time_to_string(std::filesystem::file_time_type const& ftime) {
    std::time_t cftime = std::chrono::system_clock::to_time_t(
        std::chrono::file_clock::to_sys(ftime));
    std::string str = std::asctime(std::localtime(&cftime));
    str.pop_back();  // rm the trailing '\n' put by `asctime`
    return str;
}