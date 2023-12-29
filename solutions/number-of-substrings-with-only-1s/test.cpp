#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string s;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .s = "0110111",
          .expected = 9,
      },
      {
          .s = "101",
          .expected = 2,
      },
      {
          .s = "111111",
          .expected = 21,
      },
  };

  for (const auto &[s, expected] : test_cases) {
    const auto actual = Solution::numSub(s);
    REQUIRE(expected == actual);
  }
}
