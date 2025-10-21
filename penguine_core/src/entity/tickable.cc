#include "entity/tickable.h"

void Tickable::tick(double delta_time) {
    std::cout << "I am being \'ticked\'" << std::endl;
}