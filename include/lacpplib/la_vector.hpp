#ifndef LA_VECTOR_HPP
#define LA_VECTOR_HPP

#include "lacpplib/compute_concept.hpp"
#include "lacpplib/output_concept.hpp"
#include <initializer_list>
#include <iostream>
#include <ostream>
#include <stdexcept>
#include <vector>

namespace lacpp {

template <typename T>
  requires AddableAndAssignable<T> && Outputable<T>
class la_vector {
public: // Constructors
  la_vector(std::initializer_list<T> list) : data(list){};
  la_vector(const la_vector<T> &other) : data(other.data){};
  la_vector<T> &operator=(const la_vector<T> &other) {
    data = other.data;
    return *this;
  }
  la_vector(la_vector<T> &&other) : data(std::move(other.data)){};
  la_vector<T> &operator=(la_vector<T> &&other) {
    data = std::move(other.data);
    return *this;
  }

public: // Accessors
  int dimension() const { return data.size(); }

  // 1-based indexing
  T operator[](int i) const {
    if (i < 1 || i > dimension()) {
      throw std::out_of_range("Index out of range");
    }
    return data[i - 1];
  }

  T &operator[](int i) {
    if (i < 1 || i > dimension()) {
      throw std::out_of_range("Index out of range");
    }
    return data[i - 1];
  }

  T safe_get(int i, T default_value) const {
    try {
      return data[i];
    } catch (std::out_of_range &e) {
      std::cout << "Index out of range: " << "i = " << i
                << ",  dimension = " << dimension() << std::endl;
      return default_value;
    }
  }

public: // Operations
  // Vector addition
  la_vector<T> operator+(const la_vector<T> &other) const {
    if (dimension() != other.dimension()) {
      throw std::invalid_argument("Dimension mismatch");
    }
    la_vector<T> result(*this);
    for (int i = 1; i <= dimension(); i++) {
      result[i] += other[i];
    }
    return result;
  }

  la_vector<T> &operator+=(const la_vector<T> &other) {
    if (dimension() != other.dimension()) {
      throw std::invalid_argument("Dimension mismatch");
    }
    for (int i = 1; i <= dimension(); i++) {
      (*this)[i] += other[i];
    }
    return *this;
  }

  // Scalar multiplication
  template <typename U>
    requires MultipliableAndAssignable<T, U>
  la_vector<T> operator*(U scalar) const {
    la_vector<T> result(*this);
    for (int i = 1; i <= dimension(); i++) {
      result[i] *= scalar;
    }
    return result;
  }

  template <typename U>
    requires MultipliableAndAssignable<T, U>
  la_vector<T> &operator*=(U scalar) {
    for (int i = 1; i <= dimension(); i++) {
      (*this)[i] *= scalar;
    }
    return *this;
  }

public: // Output
  friend std::ostream &operator<<(std::ostream &os, const la_vector<T> &v) {
    os << "(";
    for (int i = 1; i <= v.dimension(); i++) {
      os << v[i];
      if (i < v.dimension()) {
        os << ", ";
      }
    }
    os << ")";
    return os;
  }

private:
  std::vector<T> data;
};

// Scalar multiplication
template <typename T, typename U>
  requires Multipliable<T, U>
la_vector<T> operator*(U scalar, const la_vector<T> &v) {
  return v * scalar;
}

template <typename T, typename U>
  requires Multipliable<T, U>
la_vector<T> &operator*=(la_vector<T> &v, U scalar) {
  return v *= scalar;
}

} // namespace lacpp

#endif // LA_VECTOR_HPP