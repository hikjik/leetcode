#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    int n;
    std::vector<std::vector<int>> relations;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .n = 3,
          .relations{{1, 3}, {2, 3}},
          .expected = 2,
      },
      {
          .n = 3,
          .relations{{1, 2}, {2, 3}, {3, 1}},
          .expected = -1,
      },
  };

  for (const auto &[n, relations, expected] : test_cases) {
    const auto actual = Solution::minimumSemesters(n, relations);
    REQUIRE(expected == actual);
  }
}
