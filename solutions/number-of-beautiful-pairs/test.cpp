#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{2, 5, 1, 4},
          .expected = 5,
      },
      {
          .nums{11, 21, 12},
          .expected = 2,
      },
  };

  for (const auto &[nums, expected] : test_cases) {
    const auto actual = Solution::countBeautifulPairs(nums);
    REQUIRE(expected == actual);
  }
}
