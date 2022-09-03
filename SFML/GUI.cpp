#include <SFML/Graphics.hpp>
#include <iostream>
#include "wtypes.h"
#include "GUI.h"
#include <iostream>

GUI::GUI()
{
    //dwWidth = GetSystemMetrics(SM_CXSCREEN);
    //dwHeight = GetSystemMetrics(SM_CYSCREEN);
    dwWidth = 1920;
    dwHeight = 1080;


    window = new sf::RenderWindow(sf::VideoMode(dwWidth, dwHeight), "Viewer", sf::Style::Fullscreen);
    window->setFramerateLimit(144);
    window->display();
    window->setKeyRepeatEnabled(false);
}

 
void GUI::run()
{

    constructMainWindow();
    constructBottomWindow();
    constructLeftWindow();
    

    



    while (window->isOpen())
    {
        window->clear(sf::Color(16, 27, 36));
        sf::Event event;
        leftWindow->drawUI();

        bottomWindow->drawUI();
        mainWindow->drawUI();
        window->display();


        while (window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window->close();
            }
            // TODO
            /*
            if (event.type == sf::Event::Resized)
            {
                // update the view to the new size of the window
                sf::FloatRect visibleArea(0, 0, event.size.width, event.size.height);
                window.setView(sf::View(visibleArea));
            }
            */
            if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::Escape)
                {
                    window->close();
                }
            }
            if (event.type == sf::Event::MouseMoved)
            {
                if(mainWindow->isMouseInBounds(sf::Mouse::getPosition()))
                {
                    std::cout << "1" << std::endl;
                    mainWindow->colourPanel(sf::Color::Green);
                    //leftWindow->colourPanel(sf::Color::Black);
                    //bottomWindow->colourPanel(sf::Color::Black);
                }
                
                if(leftWindow->isMouseInBounds(sf::Mouse::getPosition()))
                {
                    std::cout << "2" << std::endl;
                    mainWindow->colourPanel(sf::Color::Black);
                    leftWindow->colourPanel(sf::Color::Green);
                    bottomWindow->colourPanel(sf::Color::Black);
                }
                if(bottomWindow->isMouseInBounds(sf::Mouse::getPosition()))
                {
                    mainWindow->colourPanel(sf::Color::Black);
                    leftWindow->colourPanel(sf::Color::Black);
                    bottomWindow->colourPanel(sf::Color::Green);
                }
                
            }
        } 

        //leftWindow->addButton(62, 65);


        
    }
}





void GUI::constructLeftWindow()
{
    leftWindow = new Window(window, dwWidth * 0.79, dwHeight * 0.80);
    leftWindow->setPosition(dwWidth * 0.2, dwHeight * 0.03);
}
void GUI::constructBottomWindow()
{
	bottomWindow = new Window(window, dwWidth * 0.79, dwHeight * 0.14);
    bottomWindow->setPosition(dwWidth * 0.2, dwHeight * 0.85);
}
void GUI::constructMainWindow()
{
	mainWindow = new Window(window, dwWidth * 0.185, dwHeight * 0.85 + dwHeight * 0.11);
    mainWindow->setPosition(dwWidth * 0.01, dwHeight * 0.03);
}

/* MATH TIME
* BORDER VALUES
* 
* 
///MAIN WINDOW




///LEFT WINDOW



///BOTTOM WINDOW


*/