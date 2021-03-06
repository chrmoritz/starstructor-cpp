/*
Starstructor, the Starbound Toolset 
Copyright (C) 2013-2014 Chris Stamford
Licensed under terms of The MIT License (MIT)

Source file contributers:
    Chris Stamford      contact: cstamford@gmail.com
*/

#ifndef STMAINWINDOW_HPP
#define STMAINWINDOW_HPP

#include "ui_mainwindow.h"

#include <QMainWindow>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget* parent = nullptr);
    MainWindow(const MainWindow& other) = delete;
    MainWindow(MainWindow&& other) = delete;
    MainWindow& operator=(const MainWindow& other) = delete;

    void frame();

private:
    Ui::ApplicationWindow m_mainWindow;
};

#endif // STMAINWINDOW_HPP