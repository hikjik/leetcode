#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string s;
    long long expected;
  };

  std::vector<TestCase> test_cases{
      {
          .s = "101",
          .expected = 1,
      },
      {
          .s = "100",
          .expected = 2,
      },
      {
          .s = "0111",
          .expected = 0,
      },
  };

  for (const auto &[s, expected] : test_cases) {
    const auto actual = Solution::minimumSteps(s);
    REQUIRE(expected == actual);
  }
}
