#include "ray.hpp"

Ray::Ray(const vector_t& origin, const vector_t& direction): m_origin(origin), m_direction(direction)
{}

auto Ray::origin() const -> const vector_t&
{
    return m_origin;
}

auto Ray::origin() -> vector_t&
{
    return m_origin;
}

auto Ray::direction() const -> const vector_t&
{
    return m_direction;
}

auto Ray::direction() -> vector_t&
{
    return m_direction;
}
