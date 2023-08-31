#pragma once

#include<SFML/Graphics.hpp>

#include<string>

struct froggy
{
	froggy(std::string filename);

	auto draw(sf::RenderWindow& window) -> void;

	auto handleButtonPressed(sf::Event& event) -> void;

	auto moveForward() -> void;
	auto moveBackward() -> void;
	auto moveLeft() -> void;
	auto moveRight() -> void;

	sf::Texture froggy_texture;
	sf::Sprite froggy_sprite;
};