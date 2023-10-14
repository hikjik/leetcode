#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string s1;
    std::string s2;
    bool expected;
  };

  std::vector<TestCase> test_cases{
      {
          .s1 = "abcd",
          .s2 = "cdab",
          .expected = true,
      },
      {
          .s1 = "abcd",
          .s2 = "dacb",
          .expected = false,
      },
  };

  for (const auto &[s1, s2, expected] : test_cases) {
    const auto actual = Solution::canBeEqual(s1, s2);
    REQUIRE(expected == actual);
  }
}
