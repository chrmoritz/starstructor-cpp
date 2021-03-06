/*
Starstructor, the Starbound Toolset 
Copyright (C) 2013-2014 Chris Stamford
Licensed under terms of The MIT License (MIT)

Source file contributers:
    Chris Stamford      contact: cstamford@gmail.com
*/

#ifndef STMATERIAL_HPP
#define STMATERIAL_HPP

#include "core/object/stasset.hpp"

#include <QString>
#include <QRectF>
#include <QFile>

#include <memory>

namespace Starstructor { namespace Core {

class MaterialRenderInfo; class PlatformRenderInfo;

class Tile final : public Asset
{
    struct TileInfo;

public:
    Tile() = delete;
    Tile(const QString& path);

    const TileInfo& info() const { return *m_info; }
    const MaterialRenderInfo& matRenderInfo() const { return *m_matRenderInfo; }
    const PlatformRenderInfo& platformRenderInfo() const { return *m_platformRenderInfo; }

private:
    struct TileInfo
    {
        QString name;
        int id;
        bool platform;
    };

    std::unique_ptr<TileInfo> m_info;
    std::unique_ptr<MaterialRenderInfo> m_matRenderInfo;
    std::unique_ptr<PlatformRenderInfo> m_platformRenderInfo;
};

class MaterialRenderInfo
{
public:
    MaterialRenderInfo() = delete;
    MaterialRenderInfo(const unsigned int& variants, const bool& multiColoured,
        const QString& framesPath);

    const unsigned int variants() const { return m_variants; }
    const bool multiColoured() const { return m_multiColoured; }
    const QFile& image() const { return m_image; }

    const QRectF tile(const unsigned int& variant = 0, 
        const unsigned int& colour = 0) const;

private:
    QFile m_image;
    unsigned int m_variants;
    bool m_multiColoured;
};

class PlatformRenderInfo
{
};

}

}

#endif // STMATERIAL_HPP