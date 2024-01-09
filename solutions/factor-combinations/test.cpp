#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    int n;
    std::vector<std::vector<int>> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .n = 12,
          .expected{{2, 6}, {3, 4}, {2, 2, 3}},
      },
      {
          .n = 1,
          .expected{},
      },
      {
          .n = 37,
          .expected{},
      },
  };

  for (const auto &[n, expected] : test_cases) {
    const auto actual = Solution::getFactors(n);
    REQUIRE_THAT(expected, Catch::Matchers::UnorderedEquals(actual));
  }
}
