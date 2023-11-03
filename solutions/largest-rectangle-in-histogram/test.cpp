#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> heights;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .heights{2, 1, 5, 6, 2, 3},
          .expected = 10,
      },
      {
          .heights{2, 4},
          .expected = 4,
      },
      {
          .heights{1, 2, 2},
          .expected = 4,
      },
  };

  SECTION("Two Pass") {
    for (const auto &[heights, expected] : test_cases) {
      const auto actual = two_pass::Solution::largestRectangleArea(heights);
      REQUIRE(expected == actual);
    }
  }

  SECTION("One Pass") {
    for (const auto &[heights, expected] : test_cases) {
      const auto actual = one_pass::Solution::largestRectangleArea(heights);
      REQUIRE(expected == actual);
    }
  }
}
