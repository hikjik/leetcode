#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    int n;
    int m;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .n = 10,
          .m = 3,
          .expected = 19,
      },
      {
          .n = 5,
          .m = 6,
          .expected = 15,
      },
      {
          .n = 5,
          .m = 1,
          .expected = -15,
      },
  };

  for (const auto &[n, m, expected] : test_cases) {
    const auto actual = Solution::differenceOfSums(n, m);
    REQUIRE(expected == actual);
  }
}
