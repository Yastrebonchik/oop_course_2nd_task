//
// Created by Karyn Cedra on 6/19/21.
//

#ifndef FT_CONTAINERS_TEST_HEADERS_HPP
# define FT_CONTAINERS_TEST_HEADERS_HPP

# include <iostream>
# include <list>
# include <vector>
# include <cmath>
# include <string>
# include "list.hpp"
# include "list_tests.hpp"
# include <exception>

# ifdef __linux__
#  define RESET "\e[0m"
#  define GREEN "\e[92m"
#  define BLUE "\e[94m"
#  define BOLD "\e[1m"
#  define CYAN "\033[36m"
# endif

# ifdef __APPLE__
#  define RESET "\e[0m"
#  define GREEN "\e[92m"
#  define BLUE "\e[94m"
#  define BOLD "\e[1m"
#  define CYAN "\033[36m"
# endif

# define GOOD "✓"
# define FAIL "❌"

#endif //FT_CONTAINERS_TEST_HEADERS_HPP
