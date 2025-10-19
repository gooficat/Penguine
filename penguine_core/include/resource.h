#ifndef RESOURCE_H
#define RESOURCE_H

#include "global.h"

struct Resource {
    Resource(const std::string& path);
    virtual void Load();
    virtual ~Resource();

    static std::string LoadTextFile(const std::string& path);

    template <typename T>
    static T LoadBinaryFile(const std::string& path);
};

#endif