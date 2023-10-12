#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<std::vector<int>> triangle;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .triangle{{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}},
          .expected = 11,
      },
      {
          .triangle{{-10}},
          .expected = -10,
      },
  };

  for (const auto &[triangle, expected] : test_cases) {
    const auto actual = Solution::minimumTotal(triangle);
    REQUIRE(expected == actual);
  }
}
