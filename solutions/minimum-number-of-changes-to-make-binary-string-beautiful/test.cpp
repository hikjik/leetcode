#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string s;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .s = "1001",
          .expected = 2,
      },
      {
          .s = "10",
          .expected = 1,
      },
      {
          .s = "0000",
          .expected = 0,
      },
  };

  for (const auto &[s, expected] : test_cases) {
    const auto actual = Solution::minChanges(s);
    REQUIRE(expected == actual);
  }
}
