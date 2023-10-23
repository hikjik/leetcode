#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{10, 20, 30, 5, 10, 50},
          .expected = 65,
      },
      {
          .nums{10, 20, 30, 40, 50},
          .expected = 150,
      },
      {
          .nums{12, 17, 15, 13, 10, 11, 12},
          .expected = 33,
      },
  };

  for (const auto &[nums, expected] : test_cases) {
    const auto actual = Solution::maxAscendingSum(nums);
    REQUIRE(expected == actual);
  }
}
