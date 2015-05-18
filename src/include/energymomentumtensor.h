/*
 *
 *    Copyright (c) 2015
 *      SMASH Team
 *
 *    GNU General Public License (GPLv3 or later)
 *
 */

#ifndef SRC_INCLUDE_ENERGYMOMENTUMTENSOR_H_
#define SRC_INCLUDE_ENERGYMOMENTUMTENSOR_H_

#include <array>
#include <cmath>

#include "fourvector.h"

namespace Smash {

/**
 * \ingroup data
 *
 * The EnergyMomentumTensor class represents a symmetric positive
 * semidifinite energy-momentum tensor \f$ T^{\mu \nu}\f$.
 */
class EnergyMomentumTensor {
 public:
  /// default constructor (nulls all components)
  EnergyMomentumTensor() {
    Tmn_.fill(0.);
  }

  /// copy constructor
  EnergyMomentumTensor(std::array<double, 10>Tmn) {
    for (size_t i = 0; i < 10; i++) {
      Tmn_[i] = Tmn[i];
    }
  }

  double &operator[](std::size_t i) { return Tmn_[i]; }
  double operator[](std::size_t i) const { return Tmn_[i]; }

  /// access the index of component \f$ (\mu, \nu) \f$.
  static size_t tmn_index(std::size_t mu, std::size_t nu) {
    const std::array<size_t, 16> indices = {0, 1, 2, 3,
                                            1, 4, 5, 6,
                                            2, 5, 7, 8,
                                            3, 6, 8, 9};
    return indices[mu + 4*nu];
  }

  /// increase this tensor by \f$T^{\mu \nu}_0\f$
  EnergyMomentumTensor inline operator+= (const EnergyMomentumTensor &Tmn0);
  /// decrease this tensor by \f$T^{\mu \nu}_0f$
  EnergyMomentumTensor inline operator-= (const EnergyMomentumTensor &Tmn0);
  /// scale this tensor by scalar \f$a\f$
  EnergyMomentumTensor inline operator*= (const double &a);
  /// divide this tensor by scalar \f$a\f$
  EnergyMomentumTensor inline operator/= (const double &a);

  /// iterates over the components
  using iterator = std::array<double, 10>::iterator;
  /// iterates over the components
  using const_iterator = std::array<double, 10>::const_iterator;

  /**
   * Find the Landau frame 4-velocity from energy-momentum tensor
   */
  FourVector landau_frame_4velocity() const;

  /**
   * Returns an iterator starting at the (0,0)th component.
   *
   * The iterator implements the RandomIterator concept. Thus, you can simply
   * write `begin() + 1` to get an iterator that points to the 1st component.
   */
  iterator begin() { return Tmn_.begin(); }

  /**
   * Returns an iterator pointing after the (3,3)th component.
   */
  iterator end() { return Tmn_.end(); }

  /// const overload of the above
  const_iterator begin() const { return Tmn_.begin(); }
  /// const overload of the above
  const_iterator end() const { return Tmn_.end(); }

  /// \see begin
  const_iterator cbegin() const { return Tmn_.cbegin(); }
  /// \see end
  const_iterator cend() const { return Tmn_.cend(); }

 private:
  /// the internal storage of the components.
  /* Tensor has 16 components, but it is symmetric, so number
     of independent components reduces to 10 */
  std::array<double, 10> Tmn_;
};

/**\ingroup logging
 * Prints out 4x4 tensor to the output stream.
 */
std::ostream &operator<<(std::ostream &, const EnergyMomentumTensor &);

EnergyMomentumTensor inline EnergyMomentumTensor::operator+= (
                                const EnergyMomentumTensor &Tmn0) {
  for (size_t i = 0; i < 10; i++) {
    Tmn_[i] += Tmn0[i];
  }
  return *this;
}

EnergyMomentumTensor inline operator+ (EnergyMomentumTensor a,
                                 const EnergyMomentumTensor &b) {
  a += b;
  return a;
}

EnergyMomentumTensor inline EnergyMomentumTensor::operator-= (
                                const EnergyMomentumTensor &Tmn0) {
  for (size_t i = 0; i < 10; i++) {
    Tmn_[i] -= Tmn0[i];
  }
  return *this;
}

EnergyMomentumTensor inline operator- (EnergyMomentumTensor a,
                                 const EnergyMomentumTensor &b) {
  a -= b;
  return a;
}

EnergyMomentumTensor inline EnergyMomentumTensor::operator*= (
                                               const double &a) {
  for (size_t i = 0; i < 10; i++) {
    Tmn_[i] *= a;
  }
  return *this;
}

inline EnergyMomentumTensor operator* (EnergyMomentumTensor a,
                                               const double &b) {
  a *= b;
  return a;
}

inline EnergyMomentumTensor operator* (const double &a,
                                         EnergyMomentumTensor b) {
  b *= a;
  return b;
}

EnergyMomentumTensor inline EnergyMomentumTensor::operator/= (
                                                const double &a) {
  for (size_t i = 0; i < 10; i++) {
    Tmn_[i] /= a;
  }
  return *this;
}

EnergyMomentumTensor inline operator/ (EnergyMomentumTensor a,
                                                const double &b) {
  a /= b;
  return a;
}

}  // namespace Smash

#endif  // SRC_INCLUDE_ENERGYMOMENTUMTENSOR_H_
