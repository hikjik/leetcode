#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string s;
    int k;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .s = "accca",
          .k = 2,
          .expected = 3,
      },
      {
          .s = "aabaab",
          .k = 3,
          .expected = 1,
      },
      {
          .s = "xxyz",
          .k = 1,
          .expected = 4,
      },
  };

  SECTION("Prefix Sums") {
    for (const auto &[s, k, expected] : test_cases) {
      const auto actual = ps::Solution::maxPartitionsAfterOperations(s, k);
      REQUIRE(expected == actual);
    }
  }

  SECTION("Memoization") {
    for (const auto &[s, k, expected] : test_cases) {
      const auto actual = memo::Solution::maxPartitionsAfterOperations(s, k);
      REQUIRE(expected == actual);
    }
  }
}
