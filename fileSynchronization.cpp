#include "fileSynchronization.hpp"


void scan(const fs::path& dir_path, FileContainer& fileContainer, std::vector<Folder>& syncFolders) {
    int currentDirIndex = -1; // -1 when no directories where found yet

    for (auto const& dir_entry : std::filesystem::recursive_directory_iterator{dir_path}) 
    {    
        if(dir_entry.is_directory()) {
            syncFolders.emplace_back(dir_entry.path());
            currentDirIndex++;
        }
        if(dir_entry.is_regular_file() && currentDirIndex > -1) {
            std::string fileName = dir_entry.path().filename();
            const auto& folderPath = dir_entry.path().parent_path();
            const auto& fileModificationTime = dir_entry.last_write_time();
            FileInfo fileInfo(fileName, folderPath, fileModificationTime);
            
            syncFolders[currentDirIndex].files.push_back(fileInfo);
            fileContainer.add(fileInfo);
        }
    }
}

void printSyncDirectories(const std::vector<Folder>& syncFolders) {
    for(const auto& folder : syncFolders) {
        std::cout << folder.folderPath_ << ":\n";
        for(const auto& file : folder.files) {
            std::cout << "\t\t-" << file.fileName_ << '\n';
        }
    }
}

void updateFile(FileInfo fileSrc, FileInfo fileDst) {
    fs::path srcPath {fileSrc.sourceDirectoryPath_ / fileSrc.fileName_};
    fs::path dstPath {fileDst.sourceDirectoryPath_ / fileDst.fileName_};
    fs::copy(srcPath, dstPath);  
}

const FileInfo& newerFile(const FileInfo& file1, const FileInfo& file2) {
    if(file1.modificationTime_ > file2.modificationTime_) {
        return file1;
    }
    return file2;
}

void sync(const fs::path& dir_path, FileContainer& allFiles, std::vector<Folder>& syncFolders) {
    
    for(const auto folder : syncFolders) {
        std::cout << "checking folder: " << folder.folderPath_ << '\n';
        for(const auto& file : allFiles.container_) {
            
            
            const auto& it = folder.contains(file.fileName_); // iterator to the file of fileName
            // if it points to the same file as file don't do anything
            if(*it == file) {
                continue;
            }
            if(it != end(folder.files)) {
                // when folder contains file then check which file is newer
                const auto& newer = newerFile(*it, file);
                updateFile(newer, file);
            }
            else {
                fs::path sourceFilePath = fs::path {file.sourceDirectoryPath_ / file.fileName_};
                fs::path destinationFilePath = fs::path {folder.folderPath_ / file.fileName_};
                fs::copy(sourceFilePath, destinationFilePath);
            }
        }
    }
}

