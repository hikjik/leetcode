#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    int n;
    std::vector<Tree> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .n = 3,
          .expected{{1, std::nullopt, 2, std::nullopt, 3},
                    {1, std::nullopt, 3, 2},
                    {2, 1, 3},
                    {3, 1, std::nullopt, std::nullopt, 2},
                    {3, 2, std::nullopt, 1}},
      },
      {
          .n = 1,
          .expected{{1}},
      },
  };

  SECTION("Recursion") {
    for (const auto &[n, expected] : test_cases) {
      const auto actual = recursion::Solution::generateTrees(n);
      REQUIRE(expected.size() == actual.size());
      for (size_t i = 0; i < actual.size(); ++i) {
        REQUIRE(expected[i] == Tree(Copy(actual[i])));
      }
    }
  }

  SECTION("Memoization") {
    for (const auto &[n, expected] : test_cases) {
      const auto actual = memo::Solution::generateTrees(n);
      REQUIRE(expected.size() == actual.size());
      for (size_t i = 0; i < actual.size(); ++i) {
        REQUIRE(expected[i] == Tree(Copy(actual[i])));
      }
    }
  }
}
