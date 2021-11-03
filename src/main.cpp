#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

int main()
{
    // create the window
    sf::RenderWindow window(sf::VideoMode(1400, 800), "Cancer Abyss");

    //window.setFramerateLimit(60);

    //object creation

    int x1 = 100;
    int y1 = 100;

    sf::CircleShape circle;
    circle.setFillColor(sf::Color::White);
    circle.setRadius(15);
    circle.setOutlineColor(sf::Color::Blue);
    circle.setOutlineThickness(5);
    circle.setPosition(x1, y1);

    bool quit = false;

    float deltaTime = 0.0f;
    const float timestep = 1.0f/144.0f; //up to 144Hz
    sf::Clock clock;


    // Loop to keep window updating
    while (window.isOpen())
    {

        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if ((event.type == sf::Event::Closed) || (quit == true))
                window.close();
        }

        deltaTime += clock.restart().asSeconds();

        while(deltaTime >= timestep)
        {
            deltaTime -= timestep;

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            {
                circle.move(15, 0);
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            {
                circle.move(-15, 0);
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
            {
                circle.move(0, -15);
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
            {
                circle.move(0, 15);
            }

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
                quit = true;
            }
        }

            // clear the window
        window.clear();

        window.draw(circle);

        //end the current frame
        window.display();

    }

    return 0;
}
