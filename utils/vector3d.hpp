#ifndef VECTOR3D_HPP
#define VECTOR3D_HPP

#include <array>

namespace utils
{

class vector3d
{
public:
    vector3d(double x = 0, double y = 0, double z = 0);

    vector3d& operator +=(const vector3d& v);
    vector3d& operator -=(const vector3d& v);
    vector3d& operator *=(double factor);
    vector3d& operator /=(double factor);

    double dot(const vector3d& v) const;

    double norm2() const;

    double norm() const;

    vector3d normalized() const;

    double x() const;
    double y() const;
    double z() const;

private:
    std::array<double, 3> m_values;
};

vector3d operator+(vector3d v1, const vector3d& v2);
vector3d operator-(vector3d v1, const vector3d& v2);
double operator*(const vector3d& v1, const vector3d& v2);
vector3d operator/(vector3d v, double factor);

}

#endif // VECTOR3D_HPP
