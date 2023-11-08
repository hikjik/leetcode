#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    int sx;
    int sy;
    int fx;
    int fy;
    int t;
    bool expected;
  };

  std::vector<TestCase> test_cases{
      {
          .sx = 2,
          .sy = 4,
          .fx = 7,
          .fy = 7,
          .t = 6,
          .expected = true,
      },
      {
          .sx = 3,
          .sy = 1,
          .fx = 7,
          .fy = 3,
          .t = 3,
          .expected = false,
      },
  };

  for (const auto &[sx, sy, fx, fy, t, expected] : test_cases) {
    const auto actual = Solution::isReachableAtTime(sx, sy, fx, fy, t);
    REQUIRE(expected == actual);
  }
}
