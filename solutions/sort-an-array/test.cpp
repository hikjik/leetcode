#include <catch.hpp>

#include <random_generator.h>
#include <solution.hpp>

TEST_CASE("Simple") {
  {
    std::vector<int> nums{5, 2, 3, 1};
    std::vector<int> expected{1, 2, 3, 5};
    REQUIRE(expected == Solution::sortArray(nums));
  }
  {
    std::vector<int> nums{5, 1, 1, 2, 0, 0};
    std::vector<int> expected{0, 0, 1, 1, 2, 5};
    REQUIRE(expected == Solution::sortArray(nums));
  }
}

TEST_CASE("Random") {
  auto generator = RandomGenerator();
  auto nums = generator.GenIntegralVector<int>(5 * 1e4, -5 * 1e4, 5 * 1e4);
  auto sorted = Solution::sortArray(nums);
  std::sort(nums.begin(), nums.end());
  REQUIRE(nums == sorted);
}
