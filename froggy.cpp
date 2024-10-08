#include "froggy.h"

froggy::froggy(std::string filename)
{
	froggy_texture.loadFromFile(filename);
	froggy_sprite.setTexture(froggy_texture);

	froggy_sprite.setPosition(sf::Vector2f(420, 820));
}

auto froggy::draw(sf::RenderWindow& window) noexcept -> void
{
	if (!is_dead)
	{
		window.draw(froggy_sprite);
	}
}

auto froggy::handleButtonPressed(sf::Event& const event) noexcept-> void
{
	if (event.key.code == sf::Keyboard::W) { moveForward();  }
	if (event.key.code == sf::Keyboard::S) { moveBackward(); }
	if (event.key.code == sf::Keyboard::A) { moveLeft();     }
	if (event.key.code == sf::Keyboard::D) { moveRight();    }
	if (event.key.code == sf::Keyboard::Q) { moveForward(); moveLeft(); }
	if (event.key.code == sf::Keyboard::E) { moveForward(); moveRight(); }
}

auto froggy::moveForward() noexcept -> void
{
	if (!((froggy_sprite.getPosition().y - froggy_sprite.getGlobalBounds().height) < 0))
	{
		froggy_sprite.setPosition(sf::Vector2f(froggy_sprite.getPosition().x, froggy_sprite.getPosition().y - froggy_sprite.getGlobalBounds().height));
	}
	else
	{
		froggy_sprite.setPosition(sf::Vector2f(froggy_sprite.getPosition().x, 820));
	}
}

auto froggy::moveBackward() noexcept-> void
{
	if (!((froggy_sprite.getPosition().y + froggy_sprite.getGlobalBounds().height) > 840))
	{
		froggy_sprite.setPosition(sf::Vector2f(froggy_sprite.getPosition().x, froggy_sprite.getPosition().y + froggy_sprite.getGlobalBounds().height));
	}
}

auto froggy::moveLeft() noexcept -> void
{
	if (!((froggy_sprite.getPosition().x - froggy_sprite.getGlobalBounds().width) < 0))
	{
		froggy_sprite.setPosition(sf::Vector2f(froggy_sprite.getPosition().x - froggy_sprite.getGlobalBounds().width, froggy_sprite.getPosition().y));
	}
}

auto froggy::moveRight() noexcept -> void
{
	if (!((froggy_sprite.getPosition().x + froggy_sprite.getGlobalBounds().width) > 840))
	{
		froggy_sprite.setPosition(sf::Vector2f(froggy_sprite.getPosition().x + froggy_sprite.getGlobalBounds().width, froggy_sprite.getPosition().y));
	}
}

auto froggy::setDead() noexcept -> void
{
	is_dead = true;
}

auto froggy::setOnLog() noexcept -> void
{
	is_on_log = true;
}

auto froggy::update() noexcept -> void
{
	if (froggy_sprite.getPosition().y >= 80 && froggy_sprite.getPosition().y <= 330 && !is_on_log)
	{
		is_dead = true;
	}
}
