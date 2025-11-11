export module System;

import std;
import <memory>;
import <unordered_map>;
import <map>;


import Entity;
import Component;

export class System
{
public:
	std::set<Entity> entities;
};