#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    int m;
    int n;
    std::vector<std::vector<int>> indices;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .m = 2,
          .n = 3,
          .indices{{0, 1}, {1, 1}},
          .expected = 6,
      },
      {
          .m = 2,
          .n = 2,
          .indices{{1, 1}, {0, 0}},
          .expected = 0,
      },
  };

  for (const auto &[m, n, indices, expected] : test_cases) {
    const auto actual = Solution::oddCells(m, n, indices);
    REQUIRE(expected == actual);
  }
}
