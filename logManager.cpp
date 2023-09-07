#include<ranges>
#include<algorithm>
#include<random>
#include<chrono>

#include "logManager.h"

using namespace std::chrono_literals;

auto logManager::randomNumber(int up_to) noexcept
{
    std::random_device device;
    std::default_random_engine engine(device());
    std::uniform_int_distribution<int> r(0, up_to);
    return r(engine);
}

logManager::logManager(std::string filename)
{
    for ([[maybe_unused]] const auto i : std::ranges::views::iota(0) | std::ranges::views::take(40))
    {
        logs.emplace_back(filename, randomNumber(320) + 60, randomNumber(820));
    }
}

auto logManager::draw(sf::RenderWindow& window) noexcept -> void
{
    for (auto& c : logs)
    {
        c.draw(window);
    }
}

auto logManager::update() noexcept -> void
{
    if ((std::chrono::system_clock::now() - lastTimePoint) >= 25ms)
    {
        for (auto& c : logs)
        {
            c.moveRight();
        }
        lastTimePoint = std::chrono::system_clock::now();
    }
}

auto logManager::froggyIsOnLog(froggy& frog) noexcept -> bool
{
    for (auto& c : logs)
    {
        if (c.hasCrashed(frog)) { return true; }
    }

    return false;
}
