#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string s;
    std::string expected;
  };

  std::vector<TestCase> test_cases{
      {
          .s = "aabcbbca",
          .expected = "ba",
      },
      {
          .s = "abcd",
          .expected = "abcd",
      },
  };

  for (const auto &[s, expected] : test_cases) {
    const auto actual = Solution::lastNonEmptyString(s);
    REQUIRE(expected == actual);
  }
}
