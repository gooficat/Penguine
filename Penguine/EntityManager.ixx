export module EntityManager;
// ------------------------
import Entity;
import Component;

import <array>;

import <queue>;
import <cassert>;

export class EntityManager
{
public:
	EntityManager()
	{
		num_living_entities = 0;
		for ( auto i = 0; i != MAX_ENTITIES; ++i )
		{
			available_entities.push( i );
		}
	}

	Entity AddEntity()
	{
		assert( num_living_entities < MAX_ENTITIES && "Exceeded maximum number of entities!" );

		Entity entity = available_entities.front();
		available_entities.pop();
		++num_living_entities;
		return entity;
	}

	void RemoveEntity( Entity entity )
	{
		assert( entity < num_living_entities && "Cannot destroy entity which does not exist!" );

		signatures [ entity ].reset();
		available_entities.push( entity );
		--num_living_entities;
	}

	void SetSignature( Entity entity, EntitySignature signature )
	{
		assert( entity < num_living_entities && "Cannot modify the signature of an entity which does not exist!" );

		signatures [ entity ] = signature;
	}

	EntitySignature GetSignature( Entity entity )
	{
		assert( entity < num_living_entities && "Cannot fetch the signature of an entity which does not exist!" );

		return signatures [ entity ];
	}

private:
	std::array<EntitySignature, MAX_ENTITIES> signatures;
	std::queue<Entity> available_entities;

	Entity num_living_entities;
};