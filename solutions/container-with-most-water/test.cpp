#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> height;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .height{1, 8, 6, 2, 5, 4, 8, 3, 7},
          .expected = 49,
      },
      {
          .height{1, 1},
          .expected = 1,
      },
  };

  for (const auto &[height, expected] : test_cases) {
    const auto actual = Solution::maxArea(height);
    REQUIRE(expected == actual);
  }
}
