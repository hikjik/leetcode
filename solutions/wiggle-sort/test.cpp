#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums;
    std::vector<int> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{3, 5, 2, 1, 6, 4},
          .expected = {3, 5, 1, 6, 2, 4},
      },
      {
          .nums{6, 6, 5, 6, 3, 8},
          .expected = {6, 6, 5, 6, 3, 8},
      },
  };

  for (auto &[nums, expected] : test_cases) {
    Solution::wiggleSort(nums);
    REQUIRE(expected == nums);
  }
}
