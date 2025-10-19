#include "resource.h"

#include <sstream>
#include <fstream>

Resource::Resource(const std::string& path) {

}
void Resource::load() {

}
Resource::~Resource() {

}

std::string Resource::loadTextFile(const std::string& path) {
   std::ifstream file(path);
   if (file.is_open() == false) {
      std::cerr << "Bingle bongle: " << path << std::endl;
      return nullptr;
   }
   std::string line;
   std::string content;
   while (std::getline(file, line)) {
      content += line + "\n";
   }
   file.close();
   return content;
}

template <typename T>
T Resource::loadBinaryFile(const std::string& path) {
    // to be implemented (if i even need it)
}