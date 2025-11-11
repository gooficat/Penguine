#include "Penguine.h"
using namespace Penguine;

import std;

class TestSystem : public System
{
	void Update( double delta_time )
	{
		std::println( "Haaaa" );
	}
};

class TestGame : public App
{
public:
	TestGame() : App()
	{
		RegisterSystem <TestSystem>();
	}

	void Update( double delta_time ) override
	{
		RetrieveSystem<TestSystem>()->Update( delta_time );
	}

	void Render () override
	{

	}
};

int main()
{
	return ( new TestGame() )->Run();
}