#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums;
    long long expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{7, 52, 2, 4},
          .expected = 596,
      },
      {
          .nums{5, 14, 13, 8, 12},
          .expected = 673,
      },
  };

  for (const auto &[nums, expected] : test_cases) {
    const auto actual = Solution::findTheArrayConcVal(nums);
    REQUIRE(expected == actual);
  }
}
