//
// Created by Karyn Cedra on 6/20/21.
//

#ifndef FT_CONTAINERS_LIST_TESTS_HPP
#define FT_CONTAINERS_LIST_TESTS_HPP

# include "test_headers.hpp"

void	list_tests();

template <typename T>
bool operator==(ft::list<T> &a, std::list<T> &b)
{
	if (a.size() != b.size())
		return (false);
	if (a.empty() != b.empty())
		return (false);
	typename ft::list<T>::iterator it = a.begin();
	typename std::list<T>::iterator it2 = b.begin();
	while (it != a.end())
	{
		if (*it != *it2)
			return (false);
		++it;
		++it2;
	}
	return (true);
};

#endif //FT_CONTAINERS_LIST_TESTS_HPP
