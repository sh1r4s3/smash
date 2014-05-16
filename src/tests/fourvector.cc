/*
 *
 *    Copyright (c) 2013-2014
 *      SMASH Team
 *
 *    GNU General Public License (GPLv3 or later)
 *
 */
#include "../include/fourvector.h"
#include "unittest.h"

using namespace Smash;

FourVector A(0.12, 0.06, 0.003, -0.15), B(0.06, 0.03, 0.0015, -0.075);
FourVector A2(0.12, 0.06, 0.003, -0.15), B2(0.06, 0.03, 0.0015, -0.075);
FourVector c(0.1, 0.6, 0.3, -0.15), d(0.01, 0.06, 0.0015, -0.75);

/* check equality - the vectors are different */
TEST(equality_different) {
  VERIFY(!(A == B));
  VERIFY(A != B);
}

/* check equality - the vectors Are the same */
TEST(equality_equal) {
  VERIFY(  A == A2);
  VERIFY(!(A != A2));
  VERIFY(  B == B2);
  VERIFY(!(B != B2));
}

TEST(comparisons) {
  /* check smaller equal */
  VERIFY(!(c <= d));
  /* check Bigger */
  VERIFY((c > d));
}

TEST(assignment) {
  /* check assignment */
  FourVector f = A;
  VERIFY(f == A);
}

TEST(addition) {
  FourVector g = B + B;
  VERIFY(A == g);
}

TEST(division) {
  A /= 2;
  VERIFY(A == B);
}
