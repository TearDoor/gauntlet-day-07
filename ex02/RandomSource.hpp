#pragma once

class RandomSource {
public:
  virtual int next(int max) = 0;
  virtual ~RandomSource() = default;
};
