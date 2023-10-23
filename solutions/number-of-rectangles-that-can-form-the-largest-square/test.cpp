#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<std::vector<int>> rectangles;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .rectangles{{5, 8}, {3, 9}, {5, 12}, {16, 5}},
          .expected = 3,
      },
      {
          .rectangles{{2, 3}, {3, 7}, {4, 3}, {3, 7}},
          .expected = 3,
      },
  };

  for (const auto &[rectangles, expected] : test_cases) {
    const auto actual = Solution::countGoodRectangles(rectangles);
    REQUIRE(expected == actual);
  }
}
