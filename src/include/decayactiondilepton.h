/*
 *
 *    Copyright (c) 2015
 *      SMASH Team
 *
 *    GNU General Public License (GPLv3 or later)
 *
 */

#ifndef SRC_INCLUDE_DECAYACTIONDILEPTON_H_
#define SRC_INCLUDE_DECAYACTIONDILEPTON_H_

#include "decayaction.h"

namespace Smash {

class DecayActionDilepton : public DecayAction {
 public:
  DecayActionDilepton(const ParticleData &p, float time_of_execution,
                      float shining_weight);

  float raw_weight_value() const override {
    return shining_weight_ * branching_;
  }

  void one_to_three() override;

 private:
  /**
   * The shining weight is a weight you apply to every Dilepton Decay. Because
   * we radiate dileptons at every timestep to increase statistics, we
   * afterwards weight them to correct the dilepton decay yields.
   */
  const float shining_weight_;
  /**
   * An additional branching factor that is multiplied with the shining weight.
   * For Dalitz decays, the primary shining weight is based on the integrated
   * width for the channel, and the branching factor corrects for the
   * differential width (evaluated at a particular dilepton mass), relative
   * to the integrated width. It is determined after the dilepton mass is fixed.
   * For direct (2-body) decays, the branching factor equals one.
   */
  float branching_ = 1.;
};

}  // namespace Smash

#endif  // SRC_INCLUDE_DECAYACTIONDILEPTON_H_
