#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string s;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .s = "dfa12321afd",
          .expected = 2,
      },
      {
          .s = "abc1111",
          .expected = -1,
      },
      {
          .s = "0777caas",
          .expected = 0,
      },
  };

  for (const auto &[s, expected] : test_cases) {
    const auto actual = Solution::secondHighest(s);
    REQUIRE(expected == actual);
  }
}
