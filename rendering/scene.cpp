#include "scene.hpp"

#include "primitives/iprimitive.hpp"

Scene::Scene()
{}

Scene::~Scene()
{}

auto Scene::getPrimitive(std::size_t index) -> primitive_t&
{
    assert(index < m_primitives.size());
    return m_primitives[index];
}

auto Scene::removePrimitive(std::size_t index) -> primitive_t
{
    assert(index < m_primitives.size());
    auto tmp = std::move(m_primitives[index]);
    m_primitives.erase(m_primitives.begin() + index);
    return tmp;
}

boost::optional<std::pair<std::size_t, double>> Scene::getFirstCollision(const Ray& ray) const
{
    auto min_dist = std::numeric_limits<double>::max();
    boost::optional<std::size_t> min_primitive;

    for(std::size_t i = 0; i < m_primitives.size(); i++)
    {
        const auto& prim = m_primitives[i];
        const auto opt_distance = prim->intersect(ray);
        if(opt_distance)
        {
            min_primitive = i;
            min_dist = *opt_distance;
        }
    }

    if(!min_primitive) return {};
    return std::make_pair(*min_primitive, min_dist);
}

std::size_t Scene::addPrimitive(primitive_t primitive)
{
    m_primitives.push_back(std::move(primitive));
    return m_primitives.size() - 1;
}
