#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<std::vector<int>> variables;
    int target;
    std::vector<int> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .variables{{2, 3, 3, 10}, {3, 3, 3, 1}, {6, 1, 1, 4}},
          .target = 2,
          .expected{0, 2},
      },
      {
          .variables{{39, 3, 1000, 1000}},
          .target = 17,
          .expected{},
      },
  };

  for (const auto &[variables, target, expected] : test_cases) {
    const auto actual = Solution::getGoodIndices(variables, target);
    REQUIRE(expected == actual);
  }
}
