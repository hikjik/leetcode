#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string s;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .s = "abbcccaa",
          .expected = 13,
      },
      {
          .s = "xy",
          .expected = 2,
      },
      {
          .s = "zzzzz",
          .expected = 15,
      },
      {
          .s = "",
          .expected = 0,
      },
  };

  for (const auto &[s, expected] : test_cases) {
    const auto actual = Solution::countHomogenous(s);
    REQUIRE(expected == actual);
  }
}
