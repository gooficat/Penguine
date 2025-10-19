#pragma once

#include "global.h"

class Tickable {
public:
    Tickable() = default;
    void tick(double delta_time);
protected:
private:
};