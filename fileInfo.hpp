#include <string>
#include <filesystem>

namespace fs = std::filesystem;

enum class FileStatus {
    newFile,
    updatedFile,
    deletedFile
};

class fileInfo {
public:
    fileInfo(std::string fileName, fs::path sourceDirPath, FileStatus status): fileName_(fileName),
        sourceDirectory_(sourceDirPath),
        status_(status)
     {}
private:
    std::string fileName_;
    fs::path sourceDirectory_;
    FileStatus status_;
};