#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string moves;
    bool expected;
  };

  std::vector<TestCase> test_cases{
      {
          .moves = "UD",
          .expected = true,
      },
      {
          .moves = "LL",
          .expected = false,
      },
  };

  for (const auto &[moves, expected] : test_cases) {
    const auto actual = Solution::judgeCircle(moves);
    REQUIRE(expected == actual);
  }
}
