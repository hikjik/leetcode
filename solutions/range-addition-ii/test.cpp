#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    int m;
    int n;
    std::vector<std::vector<int>> ops;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .m = 3,
          .n = 3,
          .ops{{2, 2}, {3, 3}},
          .expected = 4,
      },
      {
          .m = 3,
          .n = 3,
          .ops{{2, 2},
               {3, 3},
               {3, 3},
               {3, 3},
               {2, 2},
               {3, 3},
               {3, 3},
               {3, 3},
               {2, 2},
               {3, 3},
               {3, 3},
               {3, 3}},
          .expected = 4,
      },
      {
          .m = 3,
          .n = 3,
          .ops{},
          .expected = 9,
      },
  };

  for (const auto &[m, n, ops, expected] : test_cases) {
    const auto actual = Solution::maxCount(m, n, ops);
    REQUIRE(expected == actual);
  }
}
