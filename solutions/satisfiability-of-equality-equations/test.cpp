#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<std::string> equations;
    bool expected;
  };

  std::vector<TestCase> test_cases{
      {
          .equations{"a==b", "b!=a"},
          .expected = false,
      },
      {
          .equations{"b==a", "a==b"},
          .expected = true,
      },
  };

  for (const auto &[equations, expected] : test_cases) {
    const auto actual = Solution::equationsPossible(equations);
    REQUIRE(expected == actual);
  }
}
