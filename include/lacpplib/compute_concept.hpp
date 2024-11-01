#ifndef COMPUTE_CONCEPT_HPP
#define COMPUTE_CONCEPT_HPP

#include <concepts>

namespace lacpp {

template <typename T>
concept Addable = requires(T a, T b) {
  { a + b } -> std::convertible_to<T>;
};

template <typename T>
concept AddableAndAssignable = Addable<T> && requires(T a, T b) {
  { a += b } -> std::same_as<T &>;
};

template <typename T, typename U>
concept Multipliable = requires(T a, U b) {
  { a *b } -> std::convertible_to<T>;
};

template <typename T, typename U>
concept MultipliableAndAssignable = Multipliable<T, U> && requires(T a, U b) {
  { a *= b } -> std::same_as<T &>;
};

} // namespace lacpp

#endif // COMPUTE_CONCEPT_HPP