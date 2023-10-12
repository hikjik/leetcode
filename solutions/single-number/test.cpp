#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{2, 2, 1},
          .expected = 1,
      },
      {
          .nums{4, 1, 2, 1, 2},
          .expected = 4,
      },
      {
          .nums{1},
          .expected = 1,
      },
  };

  for (const auto &[nums, expected] : test_cases) {
    const auto actual = Solution::singleNumber(nums);
    REQUIRE(expected == actual);
  }
}
