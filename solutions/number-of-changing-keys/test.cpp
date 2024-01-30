#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string s;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .s = "aAbBcC",
          .expected = 2,
      },
      {
          .s = "AaAaAaaA",
          .expected = 0,
      },
  };

  for (const auto &[s, expected] : test_cases) {
    const auto actual = Solution::countKeyChanges(s);
    REQUIRE(expected == actual);
  }
}
