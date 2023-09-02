#pragma once

#include<SFML/Graphics.hpp>

#include<chrono>

#include "log.h"
#include "froggy.h"

struct logManager
{
	logManager(std::string filename);

	auto draw(sf::RenderWindow& window) noexcept -> void;

	auto randomNumber(int up_to) noexcept;

	auto update() noexcept -> void;

	auto froggyIsOnLog(froggy& frog) noexcept -> bool;

	std::vector<log> logs{};

	std::chrono::system_clock::time_point lastTimePoint = std::chrono::system_clock::now();
};