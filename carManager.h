#pragma once

#include<SFML/Graphics.hpp>

#include<chrono>

#include "car.h"
#include "froggy.h"

struct carManager
{
	carManager(std::string filename);

	auto draw(sf::RenderWindow& window) noexcept -> void;

	auto randomNumber(int up_to) noexcept;

	auto update() noexcept -> void;

	auto hasCrashed(froggy& frog) noexcept -> bool;

	std::vector<car> cars{};

	std::chrono::system_clock::time_point lastTimePoint = std::chrono::system_clock::now();
};