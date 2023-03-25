#include <catch.hpp>

#include <solution.hpp>

#include <algorithm>

bool isPermutation(std::vector<int> permutation, std::vector<int> nums) {
  return std::is_permutation(permutation.begin(), permutation.end(),
                             nums.begin());
}

TEST_CASE("Simple") {
  std::vector<int> nums{1, 2, 3};
  Solution generator(nums);
  REQUIRE(isPermutation(generator.shuffle(), nums));
  REQUIRE(nums == generator.reset());
  REQUIRE(isPermutation(generator.shuffle(), nums));
}
