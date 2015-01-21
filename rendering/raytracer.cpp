#include "raytracer.hpp"

#include "image.hpp"
#include "ray.hpp"
#include "scene.hpp"

#include "primitives/iprimitive.hpp"

Raytracer::Raytracer(Scene& scene, std::size_t pixelWidth, std::size_t pixelHeight, double width, double height, double depth):
    m_origin(),
    m_direction({0, 0, 1}),
    m_pixelWidth(pixelWidth),
    m_pixelHeight(pixelHeight),
    m_width(width),
    m_height(height),
    m_depth(depth),
    m_scene(scene),
    m_backgroundColor()
{
    updateParameters();
}

Image Raytracer::draw() const
{
    Image res(m_pixelWidth, m_pixelHeight);
    for(std::size_t j = 0; j < m_pixelHeight; ++j)
    {
        for(std::size_t i = 0; i < m_pixelWidth; ++i)
        {
            const auto color = computeColor(generateRay(i, j));
            res(i, j) = color;
        }
    }
    return res;
}

void Raytracer::setViewer(double width, double height, const vector_t& origin, const vector_t& direction)
{
    m_width = width;
    m_height = height;
    m_origin = origin;
    m_direction = direction;

    updateParameters();
}

void Raytracer::setResolution(unsigned long pixelWidth, unsigned long pixelHeight)
{
    m_pixelWidth = pixelWidth;
    m_pixelHeight = pixelHeight;

    updateParameters();
}

Ray Raytracer::generateRay(std::size_t x, std::size_t y) const
{
    vector_t direction = {m_precompWidth * (x - m_pixelWidth / 2.f), m_precompHeight * (y - m_pixelHeight / 2.f), m_depth};
    return {m_origin, direction.normalized()};
}

auto Raytracer::computeColor(const Ray& ray) const -> vector_t
{
    auto opt_index_dist = m_scene.getFirstCollision(ray);
    if(!opt_index_dist) return m_backgroundColor;

    const auto& primitive = m_scene.getPrimitive(opt_index_dist->first);
    const auto res = primitive->computeColorNormal(ray, opt_index_dist->second);
    return res.color;
}

void Raytracer::updateParameters()
{
    m_precompWidth = m_width / m_pixelWidth;
    m_precompHeight = m_height / m_pixelHeight;
}
