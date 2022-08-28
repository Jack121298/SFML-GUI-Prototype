#include "GUI.h"

GUI::GUI(int x, int y)
{
	constructLeftWindow();
	constructBottomWindow();
	constructMainWindow();
}




void GUI::constructLeftWindow()
{
	leftWindow = new Window();
}
void GUI::constructBottomWindow()
{
	bottomWindow = new Window();
}
void GUI::constructMainWindow()
{
	mainWindow = new Window();
}

