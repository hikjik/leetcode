#include <catch.hpp>

#include <solution.hpp>

#include <algorithm>

bool isPermutation(const std::vector<int> &permutation,
                   const std::vector<int> &nums) {
  return std::is_permutation(permutation.begin(), permutation.end(),
                             nums.begin());
}

TEST_CASE("Simple") {
  std::vector<int> nums{1, 2, 3};
  auto solution = Solution(nums);

  REQUIRE(isPermutation(solution.shuffle(), nums));
  REQUIRE(nums == solution.reset());
  REQUIRE(isPermutation(solution.shuffle(), nums));
}
