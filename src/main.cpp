#include <SFML/Graphics.hpp>
#include "EntityManager.hpp"
#include <filesystem>
#include <iostream>

int main()
{
    EntityManager m_EntityManager;

    /*

        add the reading and entity creating logic into a separate header or function
        or mayb even class. 


        // buildEntities(m_EntityManager,m_EntityManager);
        try {
            std::filesystem::path currentPath = std::filesystem::current_path();
            std::cout << "Current working directory: " << currentPath << std::endl;
        } catch (const std::filesystem::filesystem_error& e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }

    */
    auto window = sf::RenderWindow{ { 1920u, 1080u }, "CMake SFML Project" };
    window.setFramerateLimit(144);

    while (window.isOpen())
    {
        for (auto event = sf::Event{}; window.pollEvent(event);)
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        window.clear();
        window.display();
    }
}