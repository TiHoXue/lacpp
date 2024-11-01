#ifndef OUTPUT_CONCEPT_HPP
#define OUTPUT_CONCEPT_HPP

#include <iostream>

namespace lacpp {

template <typename T>
concept Outputable = requires(T a) {
  { std::cout << a } -> std::convertible_to<std::ostream &>;
};

} // namespace lacpp

#endif // OUTPUT_CONCEPT_HPP