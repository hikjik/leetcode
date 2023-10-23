#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string s;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .s = "0100",
          .expected = 1,
      },
      {
          .s = "10",
          .expected = 0,
      },
      {
          .s = "1111",
          .expected = 2,
      },
  };

  for (const auto &[s, expected] : test_cases) {
    const auto actual = Solution::minOperations(s);
    REQUIRE(expected == actual);
  }
}
