#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string a;
    std::string b;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .a = "aba",
          .b = "cdc",
          .expected = 3,
      },
      {
          .a = "aaa",
          .b = "bbb",
          .expected = 3,
      },
      {
          .a = "aaa",
          .b = "aaa",
          .expected = -1,
      },
  };

  for (const auto &[a, b, expected] : test_cases) {
    const auto actual = Solution::findLUSlength(a, b);
    REQUIRE(expected == actual);
  }
}
