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

void sync(const fs::path& dir_path, FileContainer& fileContainer, std::vector<Folder>& syncFolders) {
    for(const auto folder : syncFolders) {
        for(const auto& file : fileContainer.container_) {
            // when folder contains file then check which file is newer
            // if(folder.contains(file.fileName_)) {

            // }
            // else {
            //     fs::path sourceFilePath = fs::path {file.sourceDirectoryPath_ / file.fileName_};
            //     fs::path destinationFilePath = fs::path {folder.folderPath_ / file.fileName_};
            //     fs::copy(sourceFilePath, destinationFilePath);
            // }
        }
    }
}
void updateFile(fs::path fileSrc, fs::path fileDst) {
    fs::copy(fileSrc, fileDst);  
}