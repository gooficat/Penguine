#pragma once

#include "global.h"

struct Resource {
    Resource() = default;
    Resource(const std::string& path);
    virtual void Load();
    virtual ~Resource();

    static std::string LoadTextFile(const std::string& path);

    template <typename T>
    static T LoadBinaryFile(const std::string& path);
};