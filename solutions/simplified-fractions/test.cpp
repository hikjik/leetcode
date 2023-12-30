#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    int n;
    std::vector<std::string> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .n = 2,
          .expected{"1/2"},
      },
      {
          .n = 3,
          .expected{"1/2", "1/3", "2/3"},
      },
      {
          .n = 4,
          .expected{"1/2", "1/3", "1/4", "2/3", "3/4"},
      },
  };

  for (const auto &[n, expected] : test_cases) {
    const auto actual = Solution::simplifiedFractions(n);
    REQUIRE_THAT(expected, Catch::Matchers::UnorderedEquals(actual));
  }
}
