export module SystemManager;

import <cassert>;
import <memory>;
import <unordered_map>;

import Entity;
import Component;
import System;

export class SystemManager
{
public:
	template <typename T>
	std::shared_ptr<T> RegisterSystem()
	{
		std::string type_name = typeid( T ).name();

		auto system = std::make_shared<T>();
		systems.insert( { type_name, system } );
		return system;
	}

	template <typename T>
	void AssignSignature( EntitySignature signature )
	{
		std::string type_name = typeid( T ).name();

		assert( systems.find( type_name ) != system.end && "Attempted to use an unregistered system." );

		signatures.insert( { type_name, signature } );
	}

	void EntityDestroyed( Entity entity )
	{
		for ( auto const& pair : systems )
		{
			auto const& system = pair.second;

			system->entities.erase( entity );
		}
	}

private:

	std::unordered_map<std::string, EntitySignature> signatures;
	std::unordered_map<std::string, std::shared_ptr<System>> systems;
};