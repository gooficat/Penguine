export module App;

import std;

import Window;
#include "ECS.h"

import <thread>;
import <string>;
import <chrono>;

class TestSystem : public System
{
public:
	void Update( double delta_time )
	{
		std::println( "Hello, World!" );
	}
private:
};

namespace Penguine
{
	enum class GameState
	{
		RUNNING = 0
	};

	void CallTickLoop();

	export class App : public ECSCoordinator
	{
	public:
		std::shared_ptr<TestSystem> test_system;

		App() : ECSCoordinator()
		{
			std::cout << "Hello!" << std::endl;

			test_system = RegisterSystem<TestSystem>();

			tick_rate = 24.0;

			active_instance = this;

		}

		void TickLoop()
		{
			double delta_time = 0.0;
			while ( 1 )
			{
				std::chrono::high_resolution_clock::time_point start_time = std::chrono::high_resolution_clock::now();
				test_system->Update( 0.0 );

				std::chrono::high_resolution_clock::time_point end_time = std::chrono::high_resolution_clock::now();

				delta_time = std::chrono::duration<double>( end_time - start_time ).count() * 1000.0;

				std::println( "{}", delta_time );
			}
		}


		int Run()
		{
			std::cout << "Goodbye!" << std::endl;

			std::thread ticking_thread( CallTickLoop );

			ticking_thread.join();

			std::cout << "Done???" << std::endl;
			return 0;
		}


		inline static App* active_instance;
	private:
		double tick_rate;
	};

	void CallTickLoop()
	{
		App::active_instance->TickLoop();
	}

}