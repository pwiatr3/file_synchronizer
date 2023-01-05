#pragma once
#include "fileContainer.hpp"
#include "folder.hpp"

void scan(const fs::path& dir_path, FileContainer& fileContainer, std::vector<Folder>& syncFolders);
void printSyncDirectories(const std::vector<Folder>& syncFolders); 
void sync(const fs::path& dir_path, FileContainer& fileContainer, std::vector<Folder>& syncFolders);
