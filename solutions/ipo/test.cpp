#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    int k;
    int w;
    std::vector<int> profits;
    std::vector<int> capital;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .k = 2,
          .w = 0,
          .profits{1, 2, 3},
          .capital{0, 1, 1},
          .expected = 4,
      },
      {
          .k = 3,
          .w = 0,
          .profits{1, 2, 3},
          .capital{0, 1, 2},
          .expected = 6,
      },
  };

  for (const auto &[k, w, profits, capital, expected] : test_cases) {
    const auto actual = Solution::findMaximizedCapital(k, w, profits, capital);
    REQUIRE(expected == actual);
  }
}
