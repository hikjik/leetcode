#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{1, 4, 3, 1},
          .expected = 1,
      },
      {
          .nums{5, 5, 5, 10, 5},
          .expected = 2,
      },
      {
          .nums{2, 3, 4},
          .expected = 1,
      },
  };

  for (const auto &[nums, expected] : test_cases) {
    const auto actual = Solution::minimumArrayLength(nums);
    REQUIRE(expected == actual);
  }
}
