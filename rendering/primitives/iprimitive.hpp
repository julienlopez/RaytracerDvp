#ifndef IPRIMITIVE_HPP
#define IPRIMITIVE_HPP

#include "utils/noncopiable.hpp"
#include "utils/vector3d.hpp"

#include <boost/optional.hpp>

class Ray;

class iPrimitive : public utils::noncopiable
{
public:
    using vector_t = utils::vector3d;

    struct ColorNormal
    {
        vector_t color;
        vector_t normal;
    };

    virtual ~iPrimitive() = default;

    boost::optional<float> intersect(const Ray& ray) const;

    ColorNormal computeColorNormal(const Ray& ray, float dist) const;

protected:
    iPrimitive() = default;

private:
    virtual boost::optional<float> impl_intersect(const Ray& ray) const = 0;

    virtual ColorNormal impl_computeColorNormal(const Ray& ray, float dist) const = 0;
};

#endif // IPRIMITIVE_HPP
