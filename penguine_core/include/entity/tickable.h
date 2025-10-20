#pragma once

#include "global.h"

#include "entity/viewable.h"

class Tickable {
public:
    Tickable() = default;
    void tick(double delta_time);

    std::vector<shared_ptr<Viewable>> hooked_viewables;
protected:

private:
};