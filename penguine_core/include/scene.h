#pragma once

#include "global.h"

#include "node.h"

class Scene {
public:
    Scene() = default;
    void tickCallback();
    void drawCallback();

    size_t addNode();
    Node *getNode();
    bool deleteNode();
protected:
    std::map<std::string, Node*> nodes;
private:
};