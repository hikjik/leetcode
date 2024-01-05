#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string instructions;
    bool expected;
  };

  std::vector<TestCase> test_cases{
      {
          .instructions = "GGLLGG",
          .expected = true,
      },
      {
          .instructions = "GG",
          .expected = false,
      },
      {
          .instructions = "GL",
          .expected = true,
      },
  };

  for (const auto &[instructions, expected] : test_cases) {
    const auto actual = Solution::isRobotBounded(instructions);
    REQUIRE(expected == actual);
  }
}
