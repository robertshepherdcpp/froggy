#include "froggy.h"

froggy::froggy(std::string filename)
{
	froggy_texture.loadFromFile(filename);
	froggy_sprite.setTexture(froggy_texture);

	froggy_sprite.setPosition(sf::Vector2f(420, 820));
}

auto froggy::draw(sf::RenderWindow& window) -> void
{
	window.draw(froggy_sprite);
}

auto froggy::handleButtonPressed(sf::Event& event) -> void
{
	if (event.key.code == sf::Keyboard::W) { moveForward();  }
	if (event.key.code == sf::Keyboard::S) { moveBackward(); }
	if (event.key.code == sf::Keyboard::A) { moveLeft();     }
	if (event.key.code == sf::Keyboard::D) { moveRight();    }
}

auto froggy::moveForward() -> void
{
	if (!((froggy_sprite.getPosition().y - froggy_sprite.getGlobalBounds().height) < 0))
	{
		froggy_sprite.setPosition(sf::Vector2f(froggy_sprite.getPosition().x, froggy_sprite.getPosition().y - froggy_sprite.getGlobalBounds().height));
	}
}

auto froggy::moveBackward() -> void
{
	if (!((froggy_sprite.getPosition().y + froggy_sprite.getGlobalBounds().height) > 840))
	{
		froggy_sprite.setPosition(sf::Vector2f(froggy_sprite.getPosition().x, froggy_sprite.getPosition().y + froggy_sprite.getGlobalBounds().height));
	}
}

auto froggy::moveLeft() -> void
{
	if (!((froggy_sprite.getPosition().x - froggy_sprite.getGlobalBounds().width) < 0))
	{
		froggy_sprite.setPosition(sf::Vector2f(froggy_sprite.getPosition().x - froggy_sprite.getGlobalBounds().width, froggy_sprite.getPosition().y));
	}
}

auto froggy::moveRight() -> void
{
	if (!((froggy_sprite.getPosition().x + froggy_sprite.getGlobalBounds().width) > 840))
	{
		froggy_sprite.setPosition(sf::Vector2f(froggy_sprite.getPosition().x + froggy_sprite.getGlobalBounds().width, froggy_sprite.getPosition().y));
	}
}
