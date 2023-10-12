#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    int x;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .x = 123,
          .expected = 321,
      },
      {
          .x = -123,
          .expected = -321,
      },
      {
          .x = 120,
          .expected = 21,
      },
  };

  for (const auto &[x, expected] : test_cases) {
    const auto actual = Solution::reverse(x);
    REQUIRE(expected == actual);
  }
}
