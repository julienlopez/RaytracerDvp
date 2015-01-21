#ifndef SPHERE_HPP
#define SPHERE_HPP

#include "iprimitive.hpp"

class Sphere : public iPrimitive
{
public:
    Sphere(const vector_t& center, float radius, const vector_t& color);
    virtual ~Sphere() = default;

    void setColor(const vector_t& color_);

private:
    vector_t m_center;
    double m_radius;
    vector_t m_color;

    virtual boost::optional<float> impl_intersect(const Ray& ray) const override;

    virtual ColorNormal impl_computeColorNormal(const Ray& ray, float dist) const override;
};

#endif // SPHERE_HPP
