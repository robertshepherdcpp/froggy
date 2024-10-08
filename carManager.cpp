#include<ranges>
#include<algorithm>
#include<random>
#include<chrono>

#include "carManager.h"

using namespace std::chrono_literals;

auto carManager::randomNumber(int up_to) noexcept
{
    std::random_device device;
    std::default_random_engine engine(device());
    std::uniform_int_distribution<int> r(0, up_to);
    return r(engine);
}

carManager::carManager(std::string filename)
{
    for ([[maybe_unused]] const auto i : std::ranges::views::iota(0) | std::ranges::views::take(40))
    {
        cars.emplace_back(filename, randomNumber(320) + 480, randomNumber(820));
    }
}

auto carManager::draw(sf::RenderWindow& window) noexcept -> void
{
    for (car& c : cars)
    {
        c.draw(window);
    }
}

auto carManager::update() noexcept -> void
{
    if ((std::chrono::system_clock::now() - lastTimePoint) >= 25ms)
    {
        for (car& c : cars)
        {
            c.moveRight();
        }
        lastTimePoint = std::chrono::system_clock::now();
    }
}

auto carManager::hasCrashed(froggy& frog) noexcept -> bool
{
    for (car& c : cars)
    {
        if (c.hasCrashed(frog)) { return true; }
    }

    return false;
}
