#pragma once
#include "fileContainer.hpp"
#include "folder.hpp"

void scan(const fs::path& dir_path, FileContainer& fileContainer, std::vector<Folder>& syncFolders);
void printSyncDirectories(const std::vector<Folder>& syncFolders); 
void sync(const fs::path& dir_path, FileContainer& fileContainer, std::vector<Folder>& syncFolders);
void updateFile(FileInfo fileSrc, FileInfo fileDst);
const FileInfo& newerFile(const FileInfo& file1, const FileInfo& file2);
bool isSameFile(FileInfo file1, FileInfo file2);
