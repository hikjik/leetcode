#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{1, 3, 5, 2, 4, 8, 2, 2},
          .expected = 1,
      },
      {
          .nums{3},
          .expected = 3,
      },
      {
          .nums{70, 38, 21, 22},
          .expected = 22,
      },
  };

  for (const auto &[nums, expected] : test_cases) {
    const auto actual = Solution::minMaxGame(nums);
    REQUIRE(expected == actual);
  }
}
