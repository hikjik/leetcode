#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<std::string> arr;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .arr{"un", "iq", "ue"},
          .expected = 4,
      },
      {
          .arr{"cha", "r", "act", "ers"},
          .expected = 6,
      },
      {
          .arr{"abcdefghijklmnopqrstuvwxyz"},
          .expected = 26,
      },
      {
          .arr{"aa", "bb"},
          .expected = 0,
      },
  };

  for (const auto &[arr, expected] : test_cases) {
    const auto actual = Solution::maxLength(arr);
    REQUIRE(expected == actual);
  }
}
