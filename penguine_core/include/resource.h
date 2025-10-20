#ifndef RESOURCE_H
#define RESOURCE_H

#include "global.h"

struct Resource {
    Resource(const string& path);
    virtual void load();
    virtual ~Resource();

    static string loadTextFile(const string& path);

    template <typename T>
    static T loadBinaryFile(const string& path);

    string path;
};

class ResourceManager {
public:
    ResourceManager();
    void load(const string& path);

    std::map<string, shared_ptr<Resource>> resources;
private:

};

#endif