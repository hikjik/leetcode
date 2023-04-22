#include <catch.hpp>

#include <solution.hpp>

void CheckSolution(std::vector<int> nums, int val, int k) {
  std::vector<int> expected;
  for (auto a : nums) {
    if (a != val) {
      expected.push_back(a);
    }
  }
  std::sort(expected.begin(), expected.end());

  REQUIRE(k == Solution::removeElement(nums, val));

  nums.resize(k);
  std::sort(nums.begin(), nums.end());
  REQUIRE(expected == nums);
}

TEST_CASE("Simple") {
  {
    std::vector<int> nums{3, 2, 2, 3};
    int val = 3, k = 2;
    CheckSolution(nums, val, k);
  }
  {
    std::vector<int> nums{0, 1, 2, 2, 3, 0, 4, 2};
    int val = 2, k = 5;
    CheckSolution(nums, val, k);
  }
}
