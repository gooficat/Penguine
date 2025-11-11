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
	void CallTickLoop();

	export class App : public ECSCoordinator
	{
	public:

		enum class GameState
		{
			STARTUP = 0,
			RUNNING = 1,
			INACTIVE = 2,
			PAUSE = 3,
			TERMINATION = 4
		} current_state;

		App() : ECSCoordinator()
		{
			current_state = GameState::STARTUP;
			std::cout << "Hello!" << std::endl;

			tick_rate = 24.0;

			active_instance = this;
		}

		virtual void Update( double delta_time )
		{

		}


		int Run()
		{
			current_state = GameState::RUNNING;

			std::thread ticking_thread( CallTickLoop );

			RenderLoop();

			ticking_thread.join();

			std::cout << "Goodbye!" << std::endl;
			return 0;
		}


		inline static App* active_instance;
	private:
		double tick_rate;
		std::vector<std::function<void( double )>> ticked_functions;

		void AddTickedProcess( void( *func )( double ) )
		{
			ticked_functions.push_back( [ func ] ( double dt )
										{
											func( dt );
										} );
		}
		void TickLoop()
		{
			double delta_time = 0.0;
			double target_tick_duration = 1000.0 / tick_rate;


		CONTINUE_UPDATE_LOOP:
			while ( current_state < GameState::PAUSE )
			{
				auto start_time = std::chrono::steady_clock::now();

				Update( delta_time );


				auto end_time = std::chrono::steady_clock::now();
				auto elapsed_tick = end_time - start_time;

				delta_time = std::chrono::duration<double, std::milli>( elapsed_tick ).count();
			}
			if ( current_state != GameState::TERMINATION )
			{
				while ( current_state > GameState::RUNNING );

				goto CONTINUE_UPDATE_LOOP;
			}
		}

		void RenderLoop()
		{
		CONTINUE_RENDER_LOOP:
			while ( current_state < GameState::INACTIVE )
			{

			}

			if ( current_state != GameState::TERMINATION )
			{
				while ( current_state > GameState::RUNNING );

				goto CONTINUE_RENDER_LOOP;
			}
		}
	};

	void CallTickLoop()
	{
		App::active_instance->TickLoop();
	}

}