#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string s;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .s = "aaabc",
          .expected = 3,
      },
      {
          .s = "cbbd",
          .expected = 3,
      },
      {
          .s = "dddaaa",
          .expected = 2,
      },
  };

  for (const auto &[s, expected] : test_cases) {
    const auto actual = Solution::minimizedStringLength(s);
    REQUIRE(expected == actual);
  }
}
