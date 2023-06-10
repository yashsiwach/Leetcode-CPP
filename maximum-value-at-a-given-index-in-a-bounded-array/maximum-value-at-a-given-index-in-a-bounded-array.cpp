// Returns the area of a trapezoidal with length h and h - l + 1 and height l.
int64_t S(int64_t h, int64_t l) {
  return (2 * h - l + 1) * l / 2;
}

// Returns the max n such that the sum of arithemetic sequence:
//   * started as `start`
//   * with `increment`
//   * in total n items
//   * the sum does not exceed `max_sum`
int FindExtra(int start, int increment, int max_sum) {
  // (start * 2 + (n - 1) * increment) * n / 2 <= max_sum
  int64_t b = start * 2 / increment - 1;  // increment is 1 or 2 so it always divides fine.
  int64_t c = 2 * max_sum / increment;
  // Now we have n^2 + bn <= c
  
  int64_t d = std::sqrt(b * b + 4 * c);
  int n = (d - b) / 2;
  return n;
}

class Solution {
public:
  int maxValue(int n, int index, int maxSum) {
    maxSum -= n;  // Now nums[i] can be 0. We just need to add 1 at the end.
    int left = index + 1;
    int right = n - index;
    auto [small, large] = std::minmax(left, right);
    
    const int64_t A = S(large, large) + S(large, small) - large;
    if (maxSum >= A) {
      // This is the case of two trapezoidal.
      // When we "raise" them the sum increases by a constant
      // factor `n`.
      return large + (maxSum - A) / n + 1;
    }
    const int64_t B = S(small, small) * 2 - small;
    if (maxSum >= B) {
      // This is the case of One Trapezoidal + One Triangle.
      // When we "raise" them the sum increases by a arithemtic
      // sequence of common difference 1.
      return small + FindExtra(small * 2, 1, maxSum - B) + 1;
    }
    // This is the case of two triangles.
    // When we "raise" them the sum increases by a arithemtic
    // sequence of common difference 2.
    return FindExtra(1, 2, maxSum) + 1;
  }
};