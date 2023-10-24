#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string s;
    std::string expected;
  };

  std::vector<TestCase> test_cases{
      {
          .s = "aaaabbbbcccc",
          .expected = "abccbaabccba",
      },
      {
          .s = "rat",
          .expected = "art",
      },
  };

  for (const auto &[s, expected] : test_cases) {
    const auto actual = Solution::sortString(s);
    REQUIRE(expected == actual);
  }
}
