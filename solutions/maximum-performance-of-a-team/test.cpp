#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    int n;
    std::vector<int> speed;
    std::vector<int> efficiency;
    int k;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .n = 6,
          .speed{2, 10, 3, 1, 5, 8},
          .efficiency{5, 4, 3, 9, 7, 2},
          .k = 2,
          .expected = 60,
      },
      {
          .n = 6,
          .speed{2, 10, 3, 1, 5, 8},
          .efficiency{5, 4, 3, 9, 7, 2},
          .k = 3,
          .expected = 68,
      },
      {
          .n = 6,
          .speed{2, 10, 3, 1, 5, 8},
          .efficiency{5, 4, 3, 9, 7, 2},
          .k = 4,
          .expected = 72,
      },
  };

  for (const auto &[n, speed, efficiency, k, expected] : test_cases) {
    const auto actual = Solution::maxPerformance(n, speed, efficiency, k);
    REQUIRE(expected == actual);
  }
}
