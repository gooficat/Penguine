#ifndef RESOURCE_H
#define RESOURCE_H

#include "global.h"

struct Resource {
    Resource(const std::string& path);
    virtual void load();
    virtual ~Resource();

    static std::string loadTextFile(const std::string& path);

    template <typename T>
    static T loadBinaryFile(const std::string& path);

    std::string path;
};

class ResourceManager {
public:
    ResourceManager();
    void load(const std::string& path);

    std::map<std::string, std::shared_ptr<Resource>> resources;
private:

};

#endif