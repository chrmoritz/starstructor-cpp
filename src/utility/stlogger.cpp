/*
Starstructor, the Starbound Toolet
Copyright (C) 2013-2014 Chris Stamford

Source file contributers:
    Chris Stamford      contact: cstamford@gmail.com

Licensed under the terms of the GPL.
Contact: starstructor@gmail.com
*/

#include "utility/stlogger.hpp"

#include <QTextStream>
#include <QTime>
#include <QDebug>
#include <QDir>

using lockGuard = std::lock_guard<std::recursive_mutex>;

namespace Starstructor { namespace Utility {

Logger::Logger(const QString& path)
    : m_stream{}, m_logFile{path}, m_writeMutex{}
{
    // Get the directory from the full path
    const QDir dir{ QFileInfo{ m_logFile }.dir() };

    if (!dir.exists())
        dir.mkpath(".");

    if (!m_logFile.open(QIODevice::WriteOnly | QIODevice::Text))
        throw FileNotFoundException{ "Unable to open log file at " + path };

    m_stream.setDevice(&m_logFile);
    writeLine("Opened log file at " + path);
}

Logger::~Logger()
{
    writeLine("Closed log file at " + m_logFile.fileName());
    m_logFile.close();
}

Logger& Logger::operator<<(const char* input)
{
    lockGuard lock{ m_writeMutex };
    m_stream << input;
    m_stream.flush();

#ifdef ST_USE_CONSOLE
    qDebug() << input;
#endif

    return *this;
}

Logger& Logger::operator<<(const std::string& input)
{
    lockGuard lock{ m_writeMutex };
    m_stream << input.c_str();
    m_stream.flush();

#ifdef ST_USE_CONSOLE
    qDebug() << input.c_str();
#endif

    return *this;
}

Logger& Logger::operator<<(const QString& input)
{
    lockGuard lock{ m_writeMutex };
    m_stream << input; 
    m_stream.flush();

#ifdef ST_USE_CONSOLE
    qDebug() << input;
#endif

    return *this;
}

Logger& Logger::operator<<(const QVariant& input)
{
    lockGuard lock{ m_writeMutex };
    m_stream << input.toString();
    m_stream.flush();

#ifdef ST_USE_CONSOLE
    qDebug() << input;
#endif

    return *this;
}

Logger& Logger::operator<<(const Exception& input)
{
    lockGuard lock{ m_writeMutex };
    m_stream << input.what();
    m_stream.flush();

#ifdef ST_USE_CONSOLE
    qDebug() << input.what();
#endif

    return *this;
}

Logger& Logger::operator<<(const std::exception& input)
{
    lockGuard lock{ m_writeMutex };
    m_stream << input.what();
    m_stream.flush();

#ifdef ST_USE_CONSOLE
    qDebug() << input.what();
#endif

    return *this;
}

Logger& Logger::operator<<(const QTextStreamFunction& input)
{
    lockGuard lock{ m_writeMutex };
    m_stream << input;
    m_stream.flush();
    return *this;
}

void Logger::write(const char* input)
{
    lockGuard lock{ m_writeMutex };
    const QString formattedInput{ getTime() + input };
    *this << formattedInput;
}

void Logger::write(const std::string& input)
{
    lockGuard lock{ m_writeMutex };
    const QString formattedInput{ getTime() + input.c_str() };
    *this << formattedInput;
}

void Logger::write(const QString& input)
{
    lockGuard lock{ m_writeMutex };
    const QString formattedInput{ getTime() + input };
    *this << formattedInput;
}

void Logger::write(const QVariant& input)
{
    lockGuard lock{ m_writeMutex };
    const QString formattedInput{ getTime() + input.toString() };
    *this << formattedInput;
}

void Logger::write(const Exception& input)
{
    lockGuard lock{ m_writeMutex };
    const QString formattedInput{ getTime() + input.what() };
    *this << formattedInput;
}

void Logger::write(const std::exception& input)
{
    lockGuard lock{ m_writeMutex };
    const QString formattedInput{ getTime() + input.what() };
    *this << formattedInput;
}

void Logger::writeLine(const char* input)
{
    lockGuard lock{ m_writeMutex };
    write(input);
    *this << endl;
}

void Logger::writeLine(const std::string& input)
{
    lockGuard lock{ m_writeMutex };
    write(input);
    *this << endl;
}

void Logger::writeLine(const QString& input)
{
    lockGuard lock{ m_writeMutex };
    write(input);
    *this << endl;
}

void Logger::writeLine(const QVariant& input)
{
    lockGuard lock{ m_writeMutex };
    write(input);
    *this << endl;
}

void Logger::writeLine(const Exception& input)
{
    lockGuard lock{ m_writeMutex };
    write(input);
    *this << endl;
}

void Logger::writeLine(const std::exception& input)
{
    lockGuard lock{ m_writeMutex };
    write(input);
    *this << endl;
}

QString Logger::getTime()
{
    const QString format{ "HH:mm:ss zzz" };
    return "[" + QTime::currentTime().toString(format) + "] ";
}

}

}