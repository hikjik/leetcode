#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> bloomDay;
    int m;
    int k;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .bloomDay{1, 10, 3, 10, 2},
          .m = 3,
          .k = 1,
          .expected = 3,
      },
      {
          .bloomDay{1, 10, 3, 10, 2},
          .m = 3,
          .k = 2,
          .expected = -1,
      },
      {
          .bloomDay{7, 7, 7, 7, 12, 7, 7},
          .m = 2,
          .k = 3,
          .expected = 12,
      },
  };

  for (const auto &[bloomDay, m, k, expected] : test_cases) {
    const auto actual = Solution::minDays(bloomDay, m, k);
    REQUIRE(expected == actual);
  }
}
