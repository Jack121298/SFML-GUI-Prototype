#pragma once
#include "Window.h"


class GUI
{
	
public:

	GUI();
	~GUI();
	void run();

	

private:


	void update();
	void panelCheckForButtonClick();

	void constructLeftWindow();
	void constructBottomWindow();
	void constructMainWindow();
	void panelCheckForMouseHover();

	Window* leftWindow;
	Window* bottomWindow;
	Window* mainWindow;

	sf::RenderWindow* window;

	DWORD dwWidth;
	DWORD dwHeight;
	DWORD mainWindowWidthCutoff;
	DWORD mainWindowHeightCutoff;
	double RESOLUTION_RATIO_WIDTH;
	double RESOLUTION_RATIO_HEIGHT;
	


};

