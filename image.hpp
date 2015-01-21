#ifndef IMAGE_HPP
#define IMAGE_HPP

#include "utils/vector3d.hpp"

#include <vector>

class Image
{
public:
    Image(std::size_t width_, std::size_t height_);
    ~Image() = default;

    std::size_t width() const;
    std::size_t height() const;

    const utils::vector3d& operator()(std::size_t x, std::size_t y) const;
    utils::vector3d& operator()(std::size_t x, std::size_t y);

private:
    std::size_t m_width;
    std::size_t m_height;
    std::vector<utils::vector3d> m_values;
};

#endif // IMAGE_HPP
