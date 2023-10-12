#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{3, 5},
          .expected = 2,
      },
      {
          .nums{0, 0},
          .expected = -1,
      },
      {
          .nums{0, 4, 3, 0, 4},
          .expected = 3,
      },
  };

  for (const auto &[nums, expected] : test_cases) {
    const auto actual = Solution::specialArray(nums);
    REQUIRE(expected == actual);
  }
}
