#ifndef RESOURCE_H_
#define RESOURCE_H_

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

#endif