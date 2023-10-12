#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums;
    int p;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{10, 1, 2, 7, 1, 3},
          .p = 2,
          .expected = 1,
      },
      {
          .nums{4, 2, 1, 2},
          .p = 1,
          .expected = 0,
      },
  };

  for (const auto &[nums, p, expected] : test_cases) {
    const auto actual = Solution::minimizeMax(nums, p);
    REQUIRE(expected == actual);
  }
}
