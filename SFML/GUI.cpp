#include <SFML/Graphics.hpp>
#include <iostream>
#include "wtypes.h"
#include "GUI.h"
#include <iostream>

GUI::GUI()
{
    dwWidth = GetSystemMetrics(SM_CXSCREEN);
    dwHeight = GetSystemMetrics(SM_CYSCREEN);
    mainWindowWidthCutoff = dwHeight * 0.5;
    mainWindowHeightCutoff = dwHeight * 0.2;

    dwWidth = 2560;
    dwHeight = 1440;


    RESOLUTION_RATIO_WIDTH = dwWidth / 1920;
    RESOLUTION_RATIO_HEIGHT = dwHeight / 1080;



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
        
        sf::Event event;
        window->clear(sf::Color(16, 27, 36));
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
            
            if (mainWindow->isMouseInBounds(sf::Mouse::getPosition()))
            {

                mainWindow->colourPanel(sf::Color::Green);
                leftWindow->colourPanel(sf::Color::Black);
                bottomWindow->colourPanel(sf::Color::Black);
            }

            if (leftWindow->isMouseInBounds(sf::Mouse::getPosition()))
            {

                mainWindow->colourPanel(sf::Color::Black);
                leftWindow->colourPanel(sf::Color::Green);
                bottomWindow->colourPanel(sf::Color::Black);
            }
            
            if (bottomWindow->isMouseInBounds(sf::Mouse::getPosition()))
            {
                
                mainWindow->colourPanel(sf::Color::Black);
                leftWindow->colourPanel(sf::Color::Black);
                bottomWindow->colourPanel(sf::Color::Green);
            }
            
            
        }


        //leftWindow->addButton(62, 65);


        
    }
}






void GUI::constructMainWindow()
{
	mainWindow = new Window(window, dwWidth - 2 * (30 * RESOLUTION_RATIO_WIDTH) - mainWindowWidthCutoff, dwHeight - 4 * (30 * RESOLUTION_RATIO_HEIGHT) - mainWindowHeightCutoff);
    mainWindow->setPosition(30 * RESOLUTION_RATIO_WIDTH + mainWindowWidthCutoff, 30 * RESOLUTION_RATIO_HEIGHT);
}
void GUI::constructBottomWindow()
{
    bottomWindow = new Window(window, dwWidth - 2 * (30 * RESOLUTION_RATIO_WIDTH) - mainWindowWidthCutoff, dwHeight - mainWindow->getSize()->y - (3 * (30 * RESOLUTION_RATIO_HEIGHT)));
    bottomWindow->setPosition(30 * RESOLUTION_RATIO_WIDTH + mainWindowWidthCutoff, mainWindow->getSize()->y + 2 * (30 * RESOLUTION_RATIO_HEIGHT));
}
void GUI::constructLeftWindow()
{
    leftWindow = new Window(window, mainWindowWidthCutoff - (30 * RESOLUTION_RATIO_WIDTH), mainWindow->getSize()->y + bottomWindow->getSize()->y + (1 * (30 * RESOLUTION_RATIO_HEIGHT)));
    leftWindow->setPosition(30 * RESOLUTION_RATIO_WIDTH, 30 * RESOLUTION_RATIO_HEIGHT);
}
