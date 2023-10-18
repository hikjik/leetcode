#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    int n;
    std::vector<std::vector<int>> relations;
    int k;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .n = 4,
          .relations{{2, 1}, {3, 1}, {1, 4}},
          .k = 2,
          .expected = 3,
      },
      {
          .n = 5,
          .relations{{2, 1}, {3, 1}, {4, 1}, {1, 5}},
          .k = 2,
          .expected = 4,
      },
  };

  for (const auto &[n, relations, k, expected] : test_cases) {
    const auto actual = Solution::minNumberOfSemesters(n, relations, k);
    REQUIRE(expected == actual);
  }
}
