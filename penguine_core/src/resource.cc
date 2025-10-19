#include "resource.h"

#include <sstream>
#include <fstream>

Resource::Resource(const std::string& path) {

}
void Resource::Load() {

}
Resource::~Resource() {

}

std::string Resource::LoadTextFile(const std::string& path) {
    std::ifstream file(path);

    if (!file.is_open()) {
        std::cerr << "Failed to open file!" << std::endl; // this should probably be swapped for some sort of logging with termination implemented
        return "Bingle Bongle";
    }

    std::string content;

    std::string line;
    while (std::getline(file, line)) {
        content.append(line);
    }

    return content;
}

template <typename T>
T Resource::LoadBinaryFile(const std::string& path) {
    // to be implemented (if i even need it)
}