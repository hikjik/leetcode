#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{11, 7, 2, 15},
          .expected = 2,
      },
      {
          .nums{-3, 3, 3, 90},
          .expected = 2,
      },
  };

  for (const auto &[nums, expected] : test_cases) {
    const auto actual = Solution::countElements(nums);
    REQUIRE(expected == actual);
  }
}
