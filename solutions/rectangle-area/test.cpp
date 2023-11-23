#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    int ax1;
    int ay1;
    int ax2;
    int ay2;
    int bx1;
    int by1;
    int bx2;
    int by2;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .ax1 = -3,
          .ay1 = 0,
          .ax2 = 3,
          .ay2 = 4,
          .bx1 = 0,
          .by1 = -1,
          .bx2 = 9,
          .by2 = 2,
          .expected = 45,
      },
      {
          .ax1 = -2,
          .ay1 = -2,
          .ax2 = 2,
          .ay2 = 2,
          .bx1 = -2,
          .by1 = -2,
          .bx2 = 2,
          .by2 = 2,
          .expected = 16,
      },
  };

  for (const auto &[ax1, ay1, ax2, ay2, bx1, by1, bx2, by2, expected] :
       test_cases) {
    const auto actual =
        Solution::computeArea(ax1, ay1, ax2, ay2, bx1, by1, bx2, by2);
    REQUIRE(expected == actual);
  }
}
