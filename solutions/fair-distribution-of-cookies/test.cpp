#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> cookies;
    int k;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .cookies{8, 15, 10, 20, 8},
          .k = 2,
          .expected = 31,
      },
      {
          .cookies{6, 1, 3, 2, 2, 4, 1, 2},
          .k = 3,
          .expected = 7,
      },
  };

  for (const auto &[cookies, k, expected] : test_cases) {
    const auto actual = Solution::distributeCookies(cookies, k);
    REQUIRE(expected == actual);
  }
}
