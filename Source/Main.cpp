#include "Game/Game.hpp"
#include "States/MainGameState.hpp"

#include <string>
#include <iostream>

void printContextInformation() {
	std::string version = (const char*)glGetString(GL_VERSION);
	std::cout << version;
}

int main() {
	sf::ContextSettings contextSettings;
	
	// Set OpenGL version
	contextSettings.majorVersion = 4;
	contextSettings.minorVersion = 6;

	// Misc options
	contextSettings.antialiasingLevel = 8;
	contextSettings.depthBits = 24;
	contextSettings.stencilBits = 8;
	contextSettings.sRgbCapable = false;

	// Create window
	sf::RenderWindow window(sf::VideoMode(800, 600), "Game", 4u, contextSettings);

	// Only run if an OpenGL context was created
	if (glewInit() != GLEW_OK)
		return 1;

	printContextInformation();

	// Run game
	game::Game game(window);
	game.setState(std::make_unique<states::MainGameState>());
	game.run();
	return 0;
}