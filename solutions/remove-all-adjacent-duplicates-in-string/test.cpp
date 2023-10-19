#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string s;
    std::string expected;
  };

  std::vector<TestCase> test_cases{
      {
          .s = "abbaca",
          .expected = "ca",
      },
      {
          .s = "azxxzy",
          .expected = "ay",
      },
  };

  for (const auto &[s, expected] : test_cases) {
    const auto actual = Solution::removeDuplicates(s);
    REQUIRE(expected == actual);
  }
}
