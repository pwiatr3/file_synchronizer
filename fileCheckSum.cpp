#include "fileCheckSum.hpp"

std::string readFile(fs::path path)
{
    // Open the stream to 'lock' the file.
    std::ifstream f(path, std::ios::in | std::ios::binary);

    // Obtain the size of the file.
    const auto fileSize = fs::file_size(path);

    // Create a buffer.
    std::string result(fileSize, '\0');

    // Read the whole file into the buffer.
    f.read(result.data(), fileSize);

    return result;
}