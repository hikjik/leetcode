#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> original;
    int m;
    int n;
    std::vector<std::vector<int>> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .original{1, 2, 3, 4},
          .m = 2,
          .n = 2,
          .expected{{1, 2}, {3, 4}},
      },
      {
          .original{1, 2, 3},
          .m = 1,
          .n = 3,
          .expected{{1, 2, 3}},
      },
      {
          .original{1, 2},
          .m = 1,
          .n = 1,
          .expected{},
      },
  };

  for (const auto &[original, m, n, expected] : test_cases) {
    const auto actual = Solution::construct2DArray(original, m, n);
    REQUIRE(expected == actual);
  }
}
