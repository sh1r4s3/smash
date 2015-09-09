/*
 *
 *    Copyright (c) 2015
 *      SMASH Team
 *
 *    GNU General Public License (GPLv3 or later)
 *
 */

#ifndef SRC_INCLUDE_SCATTERACTIONNUCLEONKAON_H_
#define SRC_INCLUDE_SCATTERACTIONNUCLEONKAON_H_

#include "scatteraction.h"
#include "scatteractionbaryonmeson.h"

namespace Smash {


/**
 * \ingroup action
 * ScatterActionNucleonKaon is a special ScatterActionBaryonMeson which represents the
 * scattering of a nucleon and a kaon.
 */
class ScatterActionNucleonKaon : public ScatterActionBaryonMeson {
 public:
  /* Inherit constructor. */
  using ScatterActionBaryonMeson::ScatterActionBaryonMeson;
  /**
   * Determine the elastic cross section for a nucleon-kaon collision.
   * It is given by a parametrization of experimental data.
   */
  float elastic_parametrization() override;

 protected:
  /**
   * \ingroup logging
   * Writes information about this scatter action to the \p out stream.
   */
  void format_debug_output(std::ostream &out) const override;
};


}  // namespace Smash

#endif  // SRC_INCLUDE_SCATTERACTIONNUCLEONKAON_H_