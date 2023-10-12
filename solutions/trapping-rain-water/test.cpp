#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> height;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .height{0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1},
          .expected = 6,
      },
      {
          .height{4, 2, 0, 3, 2, 5},
          .expected = 9,
      },
  };

  for (const auto &[height, expected] : test_cases) {
    const auto actual = Solution::trap(height);
    REQUIRE(expected == actual);
  }
}
