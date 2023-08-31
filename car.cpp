#include "car.h"

car::car(std::string filename, int Ycoord, int Xcoord = 0)
{
	car_texture.loadFromFile(filename);
	car_sprite.setTexture(car_texture);

	y_coord = Ycoord;
	x_coord = Xcoord;

	car_sprite.setPosition(sf::Vector2f(x_coord, y_coord));
}

auto car::draw(sf::RenderWindow& window) noexcept -> void
{
	window.draw(car_sprite);
}

auto car::moveRight() noexcept -> void
{
	x_coord += 1;
	car_sprite.setPosition(sf::Vector2f(x_coord, y_coord));
}

auto car::setPosition(sf::Vector2f pos) noexcept -> void
{
	car_sprite.setPosition(pos);
}
