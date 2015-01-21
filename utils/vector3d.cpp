#include "vector3d.hpp"

#include <cmath>
#include <numeric>

namespace utils
{

vector3d::vector3d(double x, double y, double z): m_values{x, y, z}
{}

vector3d& vector3d::operator +=(const vector3d& v)
{
    for(std::size_t i = 0; i < m_values.size(); i++)
        m_values[i] += v.m_values[i];
    return *this;
}

vector3d& vector3d::operator -=(const vector3d& v)
{
    for(std::size_t i = 0; i < m_values.size(); i++)
        m_values[i] -= v.m_values[i];
    return *this;
}

vector3d& vector3d::operator *=(double factor)
{
    for(auto& v : m_values)
        v *= factor;
    return *this;
}

vector3d& vector3d::operator /=(double factor)
{
    for(auto& v : m_values)
        v /= factor;
    return *this;
}

double vector3d::dot(const vector3d& v) const
{
    return std::inner_product(m_values.cbegin(), m_values.cend(), v.m_values.cbegin(), 0.);
}

double vector3d::norm2() const
{
    return dot(*this);
}

double vector3d::norm() const
{
    return sqrt(norm2());
}

vector3d vector3d::normalized() const
{
    return *this / norm();
}

vector3d operator+(vector3d v1, const vector3d& v2)
{
    v1 += v2;
    return v1;
}

vector3d operator-(vector3d v1, const vector3d& v2)
{
    v1 -= v2;
    return v1;
}

double operator*(const vector3d& v1, const vector3d& v2)
{
    return v1.dot(v2);
}

vector3d operator/(vector3d v, double factor)
{
    v /= factor;
    return v;
}

}
