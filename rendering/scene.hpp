#ifndef SCENE_HPP
#define SCENE_HPP

#include "utils/make_unique.hpp"
#include "utils/noncopiable.hpp"

#include <vector>

#include <boost/optional.hpp>

class iPrimitive;
class Ray;

class Scene : public utils::noncopiable
{
public:
    Scene();
    ~Scene();

    using primitive_t = std::unique_ptr<iPrimitive>;

    /**
     * @brief getPrimitive
     * @param index
     * @return
     * @preconditions index is valid.
     */
    primitive_t& getPrimitive(std::size_t index);

    /**
     * @brief removePrimitive
     * @param index
     * @return
     * @preconditions index is valid.
     */
    primitive_t removePrimitive(std::size_t index);

    boost::optional<std::pair<std::size_t, double>> getFirstCollision(const Ray& ray) const;

    std::size_t addPrimitive(primitive_t primitive);

    template<class T, typename... Args> std::size_t addPrimitive(Args&&... args)
    {
        return addPrimitive(utils::make_unique<T>(std::forward<Args>(args)...));
    }

private:
    using primitive_container_t = std::vector<primitive_t>;

    primitive_container_t m_primitives;
};

#endif // SCENE_HPP
