#ifndef RAYTRACER_HPP
#define RAYTRACER_HPP

#include "utils/noncopiable.hpp"
#include "utils/vector3d.hpp"

class Image;
class Ray;
class Scene;

class Raytracer : public utils::noncopiable
{

public:
    using vector_t = utils::vector3d;

    Raytracer(Scene& scene, std::size_t pixelWidth, std::size_t pixelHeight, double width, double height, double depth);
    ~Raytracer() = default;

    Image draw() const;

    void setViewer(double width, double height, const vector_t& origin, const vector_t& direction);

    void setResolution(std::size_t pixelWidth, std::size_t pixelHeight);

private:
    vector_t m_origin;
    vector_t m_direction;
    std::size_t m_pixelWidth;
    std::size_t m_pixelHeight;
    double m_width;
    double m_height;
    double m_depth;

    double m_precompWidth;
    double m_precompHeight;

    Scene& m_scene;

    vector_t m_backgroundColor;

    Ray generateRay(std::size_t x, std::size_t y) const;

    vector_t computeColor(const Ray& ray) const;

    void updateParameters();
};

#endif // RAYTRACER_HPP
