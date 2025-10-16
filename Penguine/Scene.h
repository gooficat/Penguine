#pragma once

#include "Api.h"
#include "Node.h"

#include <list>
#include <utility>
#include <string>
#include <memory>
#include <unordered_map>

class PENGUINE_API Scene
{
public:
	Scene() {

	}
	virtual compl Scene() {

	}

	void add_node(const std::string& name, std::shared_ptr<Node> node) {
		this->nodes.insert({ name, node });
	}
	std::shared_ptr<Node> get_node(const std::string& name) {
		return this->nodes.at(name);
	}
protected:
	std::unordered_map<std::string, std::shared_ptr<Node>> nodes;
};
