/*
Starstructor, the Starbound Toolet 
Copyright (C) 2013-2014 Chris Stamford

Source file contributers:
    Chris Stamford      contact: cstamford@gmail.com

Licensed under the terms of the GPL.
Contact: starstructor@gmail.com
*/

#include "gui/mainwindow.hpp"
#include <QApplication>

int main(int argc, char* argv[])
{
	QApplication application{argc, argv};

    Starstructor::MainWindow window;
    window.show();

	return application.exec();
}

