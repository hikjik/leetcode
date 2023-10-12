#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string s;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .s = "abacaba",
          .expected = 4,
      },
      {
          .s = "ssssss",
          .expected = 6,
      },
  };

  for (const auto &[s, expected] : test_cases) {
    const auto actual = Solution::partitionString(s);
    REQUIRE(expected == actual);
  }
}
