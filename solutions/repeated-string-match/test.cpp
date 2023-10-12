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
          .a = "abcd",
          .b = "cdabcdab",
          .expected = 3,
      },
      {
          .a = "a",
          .b = "aa",
          .expected = 2,
      },
  };

  for (const auto &[a, b, expected] : test_cases) {
    const auto actual = Solution::repeatedStringMatch(a, b);
    REQUIRE(expected == actual);
  }
}
