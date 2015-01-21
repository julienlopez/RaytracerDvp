#include "image.hpp"

Image::Image(std::size_t width_, std::size_t height_): m_width(width_), m_height(height_), m_values(width_*height_)
{}

std::size_t Image::width() const
{
    return m_width;
}

std::size_t Image::height() const
{
    return m_height;
}

const utils::vector3d& Image::operator()(std::size_t x, std::size_t y) const
{
    return m_values[x + y*m_width];
}

utils::vector3d& Image::operator()(std::size_t x, std::size_t y)
{
    return m_values[x + y*m_width];
}
