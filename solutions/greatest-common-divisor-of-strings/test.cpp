#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string str1;
    std::string str2;
    std::string expected;
  };

  std::vector<TestCase> test_cases{
      {
          .str1 = "ABCABC",
          .str2 = "ABC",
          .expected = "ABC",
      },
      {
          .str1 = "ABABAB",
          .str2 = "ABAB",
          .expected = "AB",
      },
      {
          .str1 = "LEET",
          .str2 = "CODE",
          .expected = "",
      },
  };

  for (const auto &[str1, str2, expected] : test_cases) {
    const auto actual = Solution::gcdOfStrings(str1, str2);
    REQUIRE(expected == actual);
  }
}
