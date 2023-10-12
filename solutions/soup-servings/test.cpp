#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    int n;
    double expected;
  };

  std::vector<TestCase> test_cases{
      {
          .n = 50,
          .expected = 0.62500,
      },
      {
          .n = 100,
          .expected = 0.71875,
      },
  };

  for (const auto &[n, expected] : test_cases) {
    const auto actual = Solution::soupServings(n);
    REQUIRE(expected == Approx(actual));
  }
}
