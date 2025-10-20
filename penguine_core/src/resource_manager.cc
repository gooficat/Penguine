#include "resource_manager.h"


ResourceManager::ResourceManager() {

}

void ResourceManager::load(const string& path) {
   std::ifstream f(path);
   nlohmann::json data = nlohmann::json::parse(f);

   for (auto& res : data) {
      if (res["type"] == "shader") {
         std::cout << res["flag"] << std::endl;
      }
   }
}