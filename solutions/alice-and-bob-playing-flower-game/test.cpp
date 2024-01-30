#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    int n;
    int m;
    long long expected;
  };

  std::vector<TestCase> test_cases{
      {
          .n = 3,
          .m = 2,
          .expected = 3,
      },
      {
          .n = 1,
          .m = 1,
          .expected = 0,
      },
  };

  for (const auto &[n, m, expected] : test_cases) {
    const auto actual = Solution::flowerGame(n, m);
    REQUIRE(expected == actual);
  }
}
