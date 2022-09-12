// main.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file


#include "GameLoop.h"
#include "vec2.h"

int main(int argc, char* argv[])
{
	//vec2 a = vec2(2, 4);
	//vec2 b = a;
	//vec2 c = a + b;

	//std::cout << a << std::endl;
	//std::cout << a + b << std::endl;
	//std::cout << a - b << std::endl;
	//std::cout << c << std::endl;
	//a += vec2(10, 10);
	//std::cout << a << std::endl;
	


	GameLoop gameLoop;
	gameLoop.Initialise();
	gameLoop.LoadContent();

	while (gameLoop.Update()) {
		gameLoop.Render();
	}

	gameLoop.UnloadContent();
	gameLoop.Quit();

	return 0;
}