#ifndef RAY_HPP
#define RAY_HPP

#include "utils/noncopiable.hpp"
#include "utils/vector3d.hpp"

class Ray : private utils::noncopiable
{
public:
    using vector_t = utils::vector3d;

    Ray(const vector_t& origin, const vector_t& direction);

    ~Ray() = default;

    const vector_t& origin() const;
    vector_t& origin();

    const vector_t& direction() const;
    vector_t& direction();

private:
    vector_t m_origin;
    vector_t m_direction;
};

#endif // RAY_HPP
