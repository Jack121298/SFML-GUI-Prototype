#pragma once
#include "Window.h"


class GUI
{
	
public:

	GUI(int, int);
	~GUI();
	

private:

	void constructLeftWindow();
	void constructBottomWindow();
	void constructMainWindow();

	Window* leftWindow;
	Window* bottomWindow;
	Window* mainWindow;





};

