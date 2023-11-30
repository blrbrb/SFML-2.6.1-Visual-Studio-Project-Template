#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

int main(int charc, char* argv[])
{
	sf::RenderWindow window(sf::VideoMode(200,200), "new Window"); 

    //Sourced from sfml-dev.org see [Opening and managing a SFML window](https://www.sfml-dev.org/tutorials/2.6/window-window.php) for more useful info on creating, and updating RenderWindow

    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }
    }
	return 0; 
}