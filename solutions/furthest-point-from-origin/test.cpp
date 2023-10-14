#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string moves;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .moves = "L_RL__R",
          .expected = 3,
      },
      {
          .moves = "_R__LL_",
          .expected = 5,
      },
      {
          .moves = "_______",
          .expected = 7,
      },
  };

  for (const auto &[moves, expected] : test_cases) {
    const auto actual = Solution::furthestDistanceFromOrigin(moves);
    REQUIRE(expected == actual);
  }
}
