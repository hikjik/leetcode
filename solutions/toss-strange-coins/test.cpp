#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<double> prob;
    int target;
    double expected;
  };

  std::vector<TestCase> test_cases{
      {
          .prob{0.4},
          .target = 1,
          .expected = 0.40000,
      },
      {
          .prob{0.5, 0.5, 0.5, 0.5, 0.5},
          .target = 0,
          .expected = 0.03125,
      },
  };

  SECTION("Memoization") {
    for (const auto &[prob, target, expected] : test_cases) {
      const auto actual = memo::Solution::probabilityOfHeads(prob, target);
      REQUIRE(expected == Approx(actual));
    }
  }

  SECTION("Tabulation") {
    for (const auto &[prob, target, expected] : test_cases) {
      const auto actual = dp::Solution::probabilityOfHeads(prob, target);
      REQUIRE(expected == Approx(actual));
    }
  }

  SECTION("Tabulation Memory Optimized") {
    for (const auto &[prob, target, expected] : test_cases) {
      const auto actual = opt::Solution::probabilityOfHeads(prob, target);
      REQUIRE(expected == Approx(actual));
    }
  }
}
