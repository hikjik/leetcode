#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string s;
    std::vector<std::string> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .s = "K1:L2",
          .expected{"K1", "K2", "L1", "L2"},
      },
      {
          .s = "A1:F1",
          .expected{"A1", "B1", "C1", "D1", "E1", "F1"},
      },
  };

  for (const auto &[s, expected] : test_cases) {
    const auto actual = Solution::cellsInRange(s);
    REQUIRE(expected == actual);
  }
}
