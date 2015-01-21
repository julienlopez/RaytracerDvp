#ifndef VECTOR3D_HPP
#define VECTOR3D_HPP

#include <array>

namespace utils
{

class vector3d
{
public:
    vector3d(double x = 0, double y = 0, double z = 0);

private:
    std::array<double, 3> m_values;
};

}

#endif // VECTOR3D_HPP
