#ifndef NONCOPIABLE_HPP
#define NONCOPIABLE_HPP

namespace utils
{

class noncopiable
{
protected:
	noncopiable() = default;

	noncopiable(const noncopiable&) = delete;

	noncopiable& operator=(const noncopiable&) = delete;

	noncopiable(noncopiable&&) = default;

	noncopiable& operator=(noncopiable&&) = default;
};

}

#endif // NONCOPIABLE_HPP
