#include "resource_manager.h"


ResourceManager::ResourceManager() {

}

void ResourceManager::load(const string& asset_pack_path, const string& entity_pack_path) {
   std::ifstream a_file(asset_pack_path);
   nlohmann::json data = nlohmann::json::parse(a_file);
   a_file.close();

   std::ifstream e_file(asset_pack_path);
   nlohmann::json data = nlohmann::json::parse(e_file);
   e_file.close();

   for (auto& res : data) {
      if (res["type"] == "shader") {
         string path = res["path"];
         string type = res["flag"];
         string name = res["name"];
         std::cout << name << path << " " << type << std::endl;
         resources[name] = std::make_shared<ShaderResource>(path, type);
      }
   }

   for (auto& res : resources) {
      res.second->load();
   }
}