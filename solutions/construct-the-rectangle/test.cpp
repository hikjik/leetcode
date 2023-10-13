#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    int area;
    std::vector<int> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .area = 4,
          .expected{2, 2},
      },
      {
          .area = 37,
          .expected{37, 1},
      },
      {
          .area = 122122,
          .expected{427, 286},
      },
      {
          .area = 10000000,
          .expected{3200, 3125},
      },
  };

  for (const auto &[area, expected] : test_cases) {
    const auto actual = Solution::constructRectangle(area);
    REQUIRE(expected == actual);
  }
}
