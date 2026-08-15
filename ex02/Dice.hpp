#pragma once

#include "RandomSource.hpp"

class Dice {
public:
  explicit Dice(RandomSource &rng) : m_rng(rng) {}

  int roll() { return m_rng.next(6) + 1; }

private:
  RandomSource &m_rng;
};
