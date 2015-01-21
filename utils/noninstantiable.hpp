#ifndef NONINSTANTIABLE_HPP
#define NONINSTANTIABLE_HPP

#include "noncopiable.hpp"

namespace utils
{

/**
  * \brief Defines a non-instantiable class.
  */
class noninstantiable : private noncopiable
{
protected:
	noninstantiable() = delete;
};

}

#endif // NONINSTANTIABLE_HPP
