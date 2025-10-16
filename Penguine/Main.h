#pragma once

#include "Api.h"
#include "App.h"
#include <iostream>


int main(int argc, char* argv[])
{
	std::cout << "Hello from Penguine!" << std::endl;
	auto app = Penguine::CreateApp();
	app->Run();
	delete app;
	return 0;
}