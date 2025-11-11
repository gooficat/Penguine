export module ComponentManager;

import Entity;
import Component;
import ComponentGroup;

import <unordered_map>;
import <string>;
import <memory>;

export class ComponentManager
{
public:
	template <typename T>
	void RegisterComponent()
	{
		std::string type_name = typeid( T ).name();

		component_types.insert( { type_name, next_component_type } );

		component_groups.insert( { type_name, std::make_shared<ComponentGroup<T>>() } );

		++next_component_type;
	}

	template <typename T>
	ComponentType GetComponentType()
	{
		std::string type_name = typeid( T ).name();

		return component_types.at( type_name );
	}

	template <typename T>
	void AddComponent( Entity entity, T component )
	{
		GetComponentGroup<T>()->AddComponent( entity, component );
	}


	template <typename T>
	void RemoveComponent( Entity entity )
	{
		GetComponentGroup<T>()->RemoveComponent( entity );
	}


	template <typename T>
	T& GetComponent( Entity entity )
	{
		return GetComponentGroup<T>()->GetComponent( entity );
	}

	void EntityDestroyed( Entity entity )
	{
		for ( auto const& pair : component_groups )
		{
			pair.second->EntityDestroyed( entity );
		}
	}
private:
	std::unordered_map<std::string, std::shared_ptr<IComponentGroup>> component_groups;
	std::unordered_map<std::string, ComponentType> component_types;

	ComponentType next_component_type = 0;

	template <typename T>
	std::shared_ptr<ComponentGroup<T>> GetComponentGroup()
	{
		std::string type_name = typeid( T ).name();

		return std::static_pointer_cast< ComponentGroup<T> >( component_groups.at( type_name ) );
	}
};