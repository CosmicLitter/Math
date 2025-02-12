#pragma once

#include "precision.hpp"
#include <cmath>

namespace Math {

template<typename T>
class alignas(sizeof(T)*4) Vec3 {
public:
  T x, y, z;

public:
  Vec3();
  Vec3(T x, T y, T z);

  T magnitude();
  T squareMagnitude();

  void normalize();
  Vec3<T> unit() const;

  void operator+=(const Vec3<T>& v);
  void operator-=(const Vec3<T>& v);
  void operator*=(const T s);
  void operator%=(const Vec3<T>& v);

  Vec3<T> operator+(const Vec3<T>& v) const;
  Vec3<T> operator-(const Vec3<T>& v) const;
  Vec3<T> operator*(const T s) const;
  T operator*(const Vec3<T>& v) const;
  Vec3<T> operator%(const Vec3<T>& v) const;

  T dot(const Vec3<T> &v) const;
  Vec3<T> cross(const Vec3<T> &v) const;

  void componentProductUpdate(const Vec3<T> &v);
  Vec3<T> componentProduct(const Vec3<T> &v) const;

  void addScaledVector(const Vec3<T>& v, T s); 

  void invert();
  void clear();
};

using Vec3f = Vec3<float>;
using Vec3d = Vec3<double>;

/*===================IMPLEMENTATIONS==================*/
template<typename T>
Vec3<T>::Vec3() : x(T(0)), y (T(0)), z(T(0)) {}

template<typename T>
Vec3<T>::Vec3(T x, T y, T z) : x(x), y(y), z(z) {}

template<typename T>
T Vec3<T>::magnitude() {
  return (std::sqrt(x * x + y * y + z * z));
}

template<typename T>
T Vec3<T>::squareMagnitude() {
  return (x * x + y * y + z * z);
}

template<typename T>
void Vec3<T>::normalize() {
  T l = magnitude();
  if (l > 0) {
    (*this) *= ((T)1)/l;
  }
}

template<typename T>
Vec3<T> Vec3<T>::unit() const {
  Vec3<T> copy = *this;
  copy.normalize();
  return copy;
}

template<typename T>
void Vec3<T>::operator+=(const Vec3<T>& v) {
  x += v.x;
  y += v.y;
  z += v.z;
}

template<typename T>
void Vec3<T>::operator-=(const Vec3<T>& v) {
  x -= v.x;
  y -= v.y;
  z -= v.z;
}

template<typename T>
void Vec3<T>::operator*=(const T s) {
  x *= s;
  y *= s;
  z *= s;
}

template<typename T>
void Vec3<T>::operator%=(const Vec3<T>& v) {
  *this = cross(v);
}

template<typename T>
Vec3<T> Vec3<T>::operator+(const Vec3<T>& v) const {
  return Vec3<T>(x + v.x, y + v.y, z + v.z);
}

template<typename T>
Vec3<T> Vec3<T>::operator-(const Vec3<T>& v) const {
  return Vec3<T>(x - v.x, y - v.y, z - v.z);
}

template<typename T>
Vec3<T> Vec3<T>::operator*(const T s) const {
  return Vec3<T>(x * s, y * s, z * s);
}

template<typename T>
T Vec3<T>::operator*(const Vec3<T>& v) const {
  return x * v.x + y * v.y + z * v.z;
}

template<typename T>
Vec3<T> Vec3<T>::operator%(const Vec3<T>& v) const {
  return Vec3<T>(y * v.z - z * v.y,
                 z * v.x - x * v.z,
                 x * v.y - y * v.x);
}

template<typename T>
T Vec3<T>::dot(const Vec3<T>& v) const {
  return x * v.x + y * v.y + z * v.z;
}

template<typename T>
Vec3<T> Vec3<T>::cross(const Vec3<T>& v) const {
  return Vec3<T>(y * v.z - z * v.y,
                 z * v.x - x * v.z,
                 x * v.y - y * v.x);
}

template<typename T>
Vec3<T> Vec3<T>::componentProduct(const Vec3<T>& v) const {
  return Vec3<T>(x * v.x, y * v.y, z * v.z);
}

template<typename T>
void Vec3<T>::componentProductUpdate(const Vec3<T>& v) {
  x *= v.x;
  y *= v.y;
  z *= v.z;
}

template<typename T>
void Vec3<T>::addScaledVector(const Vec3<T>& v, T s) {
  x += v.x * s;
  y += v.y * s;
  z += v.z * s;
}

template<typename T>
void Vec3<T>::invert() {
  x = -x;
  y = -y;
  z = -z;
}

template<typename T>
void Vec3<T>::clear() {
  x = 0;
  y = 0;
  z = 0;
}

}
