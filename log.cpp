#include "log.h"

log::log()
{
}

log::log(const std::string filename, int Ycoord, int Xcoord)
{
	car_texture.loadFromFile(filename);
	car_sprite.setTexture(car_texture);

	y_coord = Ycoord;
	x_coord = Xcoord;

	car_sprite.setPosition(sf::Vector2f(x_coord, y_coord));
}

auto log::draw(sf::RenderWindow& window) noexcept -> void
{
	window.draw(car_sprite);
}

auto log::moveRight() noexcept -> void
{
	x_coord += 1;
	car_sprite.setPosition(sf::Vector2f(x_coord, y_coord));

	if (x_coord >= 840)
	{
		x_coord = -20;
	}
}

auto log::setPosition(sf::Vector2f pos) noexcept -> void
{
	car_sprite.setPosition(pos);
}

auto log::hasCrashed(const froggy& frog) const noexcept -> bool
{
	return car_sprite.getGlobalBounds().intersects(frog.froggy_sprite.getGlobalBounds());
}