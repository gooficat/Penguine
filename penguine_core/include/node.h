#pragma once

#include "global.h"

class Node {
public:
    Node(const std::string& name);

    void update();
    void render();

    std::string name;
protected:
    
private:

};