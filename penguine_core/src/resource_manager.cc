#include "resource_manager.h"


ResourceManager::ResourceManager() {

}

void ResourceManager::load(const string& asset_pack_path, const string& entity_pack_path) {
   std::ifstream a_file(asset_pack_path);
   nlohmann::json res_data = nlohmann::json::parse(a_file);
   a_file.close();

   std::ifstream e_file(entity_pack_path);
   nlohmann::json ent_data = nlohmann::json::parse(e_file);
   e_file.close();

   for (auto& res : res_data) {
      if (res["type"] == "shader") {
         string path = res["path"];
         string type = res["flag"];
         string name = res["name"];
         std::cout << name << path << " " << type << std::endl;
         resources[name] = make_shared<ShaderResource>(path, type);
      }
   }

   for (auto& res : resources) {
      res.second->load();
   }

   for (auto& prog : ent_data["programs"]) {
      std::cout << "loading program of vertex" << prog["vert"] << std::endl;
      programs[prog["name"]] = make_shared<ShaderProgram>(
         *(std::dynamic_pointer_cast<ShaderResource>(resources[prog["vert"]])),
         *(std::dynamic_pointer_cast<ShaderResource>(resources[prog["frag"]]))
      );
   }

   for (auto& cam : ent_data["cameras"]) {
      auto cf = cam["projection"];
      auto cp = cam["position"];
      auto cr = cam["rotation"];
      std::cout << "loading camera in position " << cam["projection"] << std::endl;
      cameras[cam["name"]] = make_shared<Camera>(
         Camera::makePerspective(
            cf["fov"],
            1,
            cf["near"],
            cf["far"]
         ),
         (float3){cp[0], cp[1], cp[2]},
         (float3){cr[0], cr[1], cr[2]}
      );
   }

   for (auto& tickable : ent_data["tickables"]) {
      tickables[tickable["name"]] = make_shared<Tickable>(

      );
   }

   for (auto& viewable : ent_data["viewables"]) {
      viewables[viewable["name"]] = make_shared<MeshViewable>(
         *(std::dynamic_pointer_cast<MeshResource>(resources[viewable["model"]]))
      ); // oh this is gonna suck to debug
   }
}