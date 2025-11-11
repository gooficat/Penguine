export module ECS;

import Entity;
import Component;
import System;
import EntityManager;
import ComponentManager;
import SystemManager;

import <memory>;

export class ECSCoordinator
{
public:
	ECSCoordinator()
	{
		entity_manager = std::make_unique<EntityManager>();
		component_manager = std::make_unique<ComponentManager>();
		system_manager = std::make_unique<SystemManager>();
	}

	Entity AddEntity()
	{
		return entity_manager->AddEntity();
	}

	void RemoveEntity( Entity entity )
	{
		entity_manager->RemoveEntity( entity );

		component_manager->EntityDestroyed( entity );
		system_manager->EntityDestroyed( entity );
	}

	template<typename T>
	void RegisterComponent()
	{
		component_manager->RegisterComponent<T>();
	}

	template<typename T>
	void AddComponent()
	{
		component_manager->AddComponent<T>();
	}

	template<typename T>
	void RemoveComponent()
	{
		component_manager->RemoveComponent<T>();
	}

	template<typename T>
	void GetComponent()
	{
		component_manager->GetComponent<T>();
	}

	template<typename T>
	void GetComponentType()
	{
		component_manager->GetComponent<T>();
	}

	template<typename T>
	std::shared_ptr<T> RegisterSystem()
	{
		return system_manager->RegisterSystem<T>();
	}

	template<typename T>
	void AssignSignature( EntitySignature signature )
	{
		return system_manager->AssignSignature<T>( signature );
	}

	template<typename T>
	std::shared_ptr<T>& RetrieveSystem()
	{
		return system_manager->RetrieveSystem<T>();
	}
private:
	std::unique_ptr<EntityManager> entity_manager;
	std::unique_ptr<ComponentManager> component_manager;
	std::unique_ptr<SystemManager> system_manager;
};