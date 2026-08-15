#include "catch_amalgamated.hpp"

#include "Dice.hpp"
#include "RandomSource.hpp"

class FakeRandom : public RandomSource {
public:
  FakeRandom(int value) : m_value(value) {}
  int next(int) { return m_value; }

private:
  int m_value;
};

TEST_CASE("rng value 0 gives face 1") {
  FakeRandom rng(0);
  Dice dice(rng);
  CHECK(dice.roll() == 1);
}

TEST_CASE("rng value 5 gives face 6") {
  FakeRandom rng(5);
  Dice dice(rng);
  CHECK(dice.roll() == 6);
}
