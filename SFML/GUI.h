#pragma once
#include "Window.h"


class GUI
{
	
public:

	GUI();
	~GUI();
	void run();

	

private:

	void constructLeftWindow();
	void constructBottomWindow();
	void constructMainWindow();

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

