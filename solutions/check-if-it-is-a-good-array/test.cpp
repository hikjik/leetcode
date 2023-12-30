#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums;
    bool expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{12, 5, 7, 23},
          .expected = true,
      },
      {
          .nums{29, 6, 10},
          .expected = true,
      },
      {
          .nums{3, 6},
          .expected = false,
      },
  };

  for (const auto &[nums, expected] : test_cases) {
    const auto actual = Solution::isGoodArray(nums);
    REQUIRE(expected == actual);
  }
}
