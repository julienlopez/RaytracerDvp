#include "sphere.hpp"

#include "rendering/ray.hpp"

Sphere::Sphere(const vector_t& center, float radius, const vector_t& color):
    m_center(center), m_radius(radius), m_color(color)
{}

void Sphere::setColor(const vector_t& color_)
{
    m_color = color_;
}

boost::optional<float> Sphere::impl_intersect(const Ray& ray) const
{
    const double A = 1;
    const auto B = ray.direction() * (ray.origin() - m_center);
    const auto C = (ray.origin() - m_center).norm2() - m_radius * m_radius;

    const auto delta = (B * B - A * C);

    if(delta < 0.f)
        return {};
    const auto disc = sqrt(delta);
    auto dist = - (B + disc);
    if(dist < 0.)
        dist = - (B - disc);
    return dist;
}

auto Sphere::impl_computeColorNormal(const Ray& ray, float dist) const -> ColorNormal
{
    const auto collide = ray.origin() + dist*ray.direction();
    return {m_color, (collide - m_center).normalized()};
}
