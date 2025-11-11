export module Entity;

import <cstdint>;
import <bitset>;
import <array>;

import <queue>;
import <cassert>;

import Component;

export using Entity = std::uint32_t;
export using EntitySignature = std::bitset<MAX_COMPONENTS>;
export const Entity MAX_ENTITIES = 1024;