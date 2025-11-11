export module SystemManager;

import <memory>;
import <map>;

import Entity;
import Component;
import System;

export class SystemManager
{
public:
	template <typename T>
	void RegisterSystem()
	{
		std::string type_name = typeid( T ).name();

		auto system = std::make_shared<T>();
		systems.insert( { type_name, system } );
	}

	template <typename T>
	void AssignSignature( EntitySignature signature )
	{
		std::string type_name = typeid( T ).name();

		signatures.insert( { type_name, signature } );
	}

	template<typename T>
	std::shared_ptr<T> RetrieveSystem()
	{
		std::string type_name = typeid( T ).name();

		return std::static_pointer_cast< T >( systems.at( type_name ) );
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

	std::map<std::string, EntitySignature> signatures;
	std::map<std::string, std::shared_ptr<System>> systems;
};