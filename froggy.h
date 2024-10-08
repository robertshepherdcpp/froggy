#pragma once

#include<SFML/Graphics.hpp>

#include<string>

struct froggy
{
	froggy(std::string filename);

	auto draw(sf::RenderWindow& window) noexcept -> void;

	auto handleButtonPressed(sf::Event& const event) noexcept -> void;

	auto moveForward() noexcept -> void;
	auto moveBackward() noexcept-> void;
	auto moveLeft() noexcept -> void;
	auto moveRight() noexcept -> void;

	auto setDead() noexcept -> void;
	auto setOnLog() noexcept -> void;

	auto update() noexcept -> void;

	sf::Texture froggy_texture;
	sf::Sprite froggy_sprite;

	bool is_dead = false;
	bool is_on_log = false;
};