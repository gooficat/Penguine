export module ComponentGroup;
// ------------------------

import Component;
import Entity;

import <array>;
import <unordered_map>;
import <cassert>;


export
class IComponentGroup
{
public:
	virtual ~IComponentGroup() = default;
	virtual void EntityDestroyed( Entity entity ) = 0;
};


export
template <typename T>
class ComponentGroup : public IComponentGroup
{
public:
	void InsertComponent( Entity entity, T component )
	{
		assert( entity_index_map.find( entity ) == entity_index_map.end() && "Attempting to add a component that already exists in an entity." );

		entity_index_map.at( entity ) = size;
		index_entity_map.at( size ) = entity;
		components.at( size ) = component;

		++size;
	}

	void RemoveComponent( Entity entity )
	{
		assert( entity_index_map.find( entity ) != entity_index_map.end() && "Attempting to remove a component from an entity that does not have that component." );

		size_t entity_index = entity_index_map.at( entity );
		size_t end_index = size - 1;
		components [ entity_index ] = end_index;

		Entity end_entity = index_entity_map.at( end_index );
		entity_index_map.at( end_entity ) = entity_index;

		entity_index_map.erase( entity );
		index_entity_map.erase( end_index );

		--size;
	}

	T& GetComponent( Entity entity )
	{
		assert( entity_index_map.find( entity ) != entity_index_map.end() && "Attempting to access a component for an entity that does nto have that component." );

		return components.at( entity );
	}

	void EntityDestroyed( Entity entity ) override
	{
		if ( entity_index_map.find( entity ) != entity_index_map.end() )
		{
			RemoveComponent( entity );
		}
	}

private:
	std::array<T, MAX_ENTITIES> components;

	std::unordered_map<Entity, size_t> entity_index_map; // perhaps it could be map in production version

	std::unordered_map<size_t, Entity> index_entity_map;

	size_t size;
};
