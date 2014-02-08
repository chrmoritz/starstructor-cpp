/*
Starstructor, the Starbound Toolet
Copyright (C) 2013-2014 Chris Stamford

Source file contributers:
    Chris Stamford      contact: cstamford@gmail.com

Licensed under the terms of the GPL.
Contact: starstructor@gmail.com
*/

#include "core/world/stworldfile.hpp"

namespace Starstructor { namespace Core {

WorldFile::WorldFile(const std::string& path)
    : m_json{ path }
{
}

}

}