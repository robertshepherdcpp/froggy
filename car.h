#pragma once

#include<SFML/Graphics.hpp>

#include "froggy.h"

struct car
{
	car(std::string filename, int y_coord, int Xcoord = 0);

	auto draw(sf::RenderWindow& window) noexcept -> void;

	auto moveRight() noexcept -> void;

	auto setPosition(sf::Vector2f pos) noexcept -> void;

	auto hasCrashed(froggy& frog) noexcept -> bool;

	int x_coord = 0;
	int y_coord = 0;

	sf::Texture car_texture;
	sf::Sprite car_sprite;

	bool is_dead = false;
};