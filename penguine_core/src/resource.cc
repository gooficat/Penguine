#include "resource.h"

#include <sstream>
#include <fstream>

Resource::Resource(const string& path) : path(path) {

}
void Resource::load() {

}
Resource::~Resource() {

}

string Resource::loadTextFile(const string& path) {
   std::ifstream file(path);
   if (file.is_open() == false) {
      std::cerr << "Bingle bongle: " << path << std::endl;
      return "Bingle Bongle dingle dangle";
   }
   string line;
   string content;
   while (std::getline(file, line)) {
      content += line + "\n";
   }
   file.close();
   return content;
}

template <typename T>
T Resource::loadBinaryFile(const string& path) {
    // to be implemented (if i even need it)
}
