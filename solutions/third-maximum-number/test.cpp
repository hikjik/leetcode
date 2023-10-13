#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{3, 2, 1},
          .expected = 1,
      },
      {
          .nums{1, 2},
          .expected = 2,
      },
      {
          .nums{2, 2, 3, 1},
          .expected = 1,
      },
  };

  for (const auto &[nums, expected] : test_cases) {
    const auto actual = Solution::thirdMax(nums);
    REQUIRE(expected == actual);
  }
}
