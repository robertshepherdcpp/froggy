#pragma once

#include<SFML/Graphics.hpp>

struct car
{
	explicit car(std::string filename, int y_coord, int Xcoord = 0);

	auto draw(sf::RenderWindow& window) noexcept -> void;

	auto moveRight() noexcept -> void;

	auto setPosition(sf::Vector2f pos) noexcept -> void;

	int x_coord = 0;
	int y_coord = 0;

	sf::Texture car_texture;
	sf::Sprite car_sprite;
};