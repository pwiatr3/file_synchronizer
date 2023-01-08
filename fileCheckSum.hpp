#pragma once

#include <iostream>
#include <string>
#include <filesystem>
#include <fstream>

namespace fs = std::filesystem;

std::string readFile(fs::path path);


