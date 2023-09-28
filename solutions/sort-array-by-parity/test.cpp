#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  std::vector<int> nums{0};
  REQUIRE(nums == Solution::sortArrayByParity(nums));
}

TEST_CASE("Is Partitioned") {
  std::vector<int> nums{3, 1, 2, 4};
  const auto actual = Solution::sortArrayByParity(nums);
  REQUIRE(std::is_partitioned(actual.begin(), actual.end(),
                              [](int a) { return a % 2 == 0; }));
}
