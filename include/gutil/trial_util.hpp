/**
 * Author: Nu11able
 * Date: 2024-08-04
 * License: MIT License
 */

#pragma once
#include <type_traits>

template<typename T, typename = void>
struct is_container : public std::false_type {};

template<typename T>
struct is_container<T, std::void_t<
    typename T::value_type,
    typename T::begin,
    typename T::end>
> : public std::true_type {};

