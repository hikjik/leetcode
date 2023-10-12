#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    int n;
    int m;
    int k;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .n = 2,
          .m = 3,
          .k = 1,
          .expected = 6,
      },
      {
          .n = 5,
          .m = 2,
          .k = 3,
          .expected = 0,
      },
      {
          .n = 9,
          .m = 1,
          .k = 1,
          .expected = 1,
      },
  };

  for (const auto &[n, m, k, expected] : test_cases) {
    const auto actual = Solution::numOfArrays(n, m, k);
    REQUIRE(expected == actual);
  }
}
