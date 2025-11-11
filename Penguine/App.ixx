export module App;

import std;

import Window;
#include "ECS.h"

import <thread>;
import <string>;
import <chrono>;

namespace Penguine
{
	void CallTickLoop();

	export class App : public ECSCoordinator
	{
	public:

		enum class AppState
		{
			STARTUP = 0,
			RUNNING = 1,
			INACTIVE = 2,
			PAUSE = 3,
			TERMINATION = 4
		} current_state;

		App() : ECSCoordinator()
		{
			current_state = AppState::STARTUP;
			std::cout << "Hello!" << std::endl;

			tick_rate = 24.0;

			active_instance = this;
		}

		virtual void Update( double delta_time )
		{

		}

		virtual void Render()
		{

		}


		int Run()
		{
			current_state = AppState::RUNNING;

			std::thread ticking_thread( CallTickLoop );

			RenderLoop();

			ticking_thread.join();

			std::cout << "Goodbye!" << std::endl;
			return 0;
		}


		inline static App* active_instance;
		double tick_rate;

		void TickLoop()
		{
			double delta_time = 0.0;
			double target_tick_duration = 1000.0 / tick_rate;


		CONTINUE_UPDATE_LOOP:
			while ( current_state < AppState::PAUSE )
			{
				auto start_time = std::chrono::steady_clock::now();

				Update( delta_time );


				auto end_time = std::chrono::steady_clock::now();
				auto elapsed_tick = end_time - start_time;

				delta_time = std::chrono::duration<double, std::milli>( elapsed_tick ).count();
				//std::println( "{}", delta_time );
			}
			if ( current_state != AppState::TERMINATION )
			{
				while ( current_state > AppState::RUNNING );

				goto CONTINUE_UPDATE_LOOP;
			}
		}

		void RenderLoop()
		{
		CONTINUE_RENDER_LOOP:
			while ( current_state < AppState::INACTIVE )
			{
				Render();
			}

			if ( current_state != AppState::TERMINATION )
			{
				while ( current_state > AppState::RUNNING );

				goto CONTINUE_RENDER_LOOP;
			}
		}
	};

	void CallTickLoop()
	{
		App::active_instance->TickLoop();
	}

}