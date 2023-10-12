#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{2, 2, 3, 4},
          .expected = 3,
      },
      {
          .nums{4, 2, 3, 4},
          .expected = 4,
      },
  };

  for (const auto &[nums, expected] : test_cases) {
    const auto actual = Solution::triangleNumber(nums);
    REQUIRE(expected == actual);
  }
}
