#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string currentState;
    std::vector<std::string> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .currentState = "++++",
          .expected{"--++", "+--+", "++--"},
      },
      {
          .currentState = "+",
          .expected{},
      },
  };

  for (const auto &[currentState, expected] : test_cases) {
    const auto actual = Solution::generatePossibleNextMoves(currentState);
    REQUIRE(expected == actual);
  }
}
