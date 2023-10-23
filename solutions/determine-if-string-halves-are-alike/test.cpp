#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string s;
    bool expected;
  };

  std::vector<TestCase> test_cases{
      {
          .s = "book",
          .expected = true,
      },
      {
          .s = "textbook",
          .expected = false,
      },
  };

  for (const auto &[s, expected] : test_cases) {
    const auto actual = Solution::halvesAreAlike(s);
    REQUIRE(expected == actual);
  }
}
