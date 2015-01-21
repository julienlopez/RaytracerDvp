#include "iprimitive.hpp"

boost::optional<float> iPrimitive::intersect(const Ray& ray) const
{
    return impl_intersect(ray);
}

auto iPrimitive::computeColorNormal(const Ray& ray, float dist) const -> ColorNormal
{
    return impl_computeColorNormal(ray, dist);
}
