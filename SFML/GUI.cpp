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
    

   

    window->clear(sf::Color(255, 255, 255));
    leftWindow->firstRender();
    bottomWindow->firstRender();
    mainWindow->firstRender();

    Button* button = new Button(new sf::Vector2f((mainWindowWidthCutoff - (30 * RESOLUTION_RATIO_WIDTH)) * 0.8, 20));
    button->setPosition(30 * RESOLUTION_RATIO_WIDTH + ((mainWindowWidthCutoff - (30 * RESOLUTION_RATIO_WIDTH)) - (mainWindowWidthCutoff - (30 * RESOLUTION_RATIO_WIDTH)) * 0.8)/2, 100);


    mainWindow->addButton(button);
    
    window->display();

    while (window->isOpen())
    {
        window->clear(sf::Color(0, 0, 0));
        sf::Event event;
       


        while (window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window->close();
            }
          
            if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::Escape)
                {
                    window->close();
                }
            }
            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.key.code == sf::Mouse::Left)
                {
                    panelCheckForButtonClick();
                }
            }
            if (event.type == sf::Event::MouseButtonReleased)
            {
                if (event.key.code == sf::Mouse::Left)
                {
                    panelCheckForMouseHover();
                }
            }
            if (event.type == sf::Event::MouseMoved)
            {
                panelCheckForMouseHover();
            }
        }
        update();

    }
}

void GUI::update()
{
    leftWindow->drawUI();
    bottomWindow->drawUI();
    mainWindow->drawUI();
    window->display();
}



void GUI::panelCheckForButtonClick()
{
    leftWindow->checkForButtonClick();
    //std::cout << "1" << std::endl;
    bottomWindow->checkForButtonClick();
    //std::cout << "2" << std::endl;
    mainWindow->checkForButtonClick();
    //std::cout << "3" << std::endl;
}


void GUI::panelCheckForMouseHover()
{
    leftWindow->checkForMouseHover();
    //std::cout << "1" << std::endl;
    bottomWindow->checkForMouseHover();
    //std::cout << "2" << std::endl;
    mainWindow->checkForMouseHover();
    //std::cout << "3" << std::endl;
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
