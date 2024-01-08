#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<std::vector<int>> items;
    std::vector<std::vector<int>> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .items{{1, 91},
                 {1, 92},
                 {2, 93},
                 {2, 97},
                 {1, 60},
                 {2, 77},
                 {1, 65},
                 {1, 87},
                 {1, 100},
                 {2, 100},
                 {2, 76}},
          .expected{{1, 87}, {2, 88}},
      },
      {
          .items{{1, 100},
                 {7, 100},
                 {1, 100},
                 {7, 100},
                 {1, 100},
                 {7, 100},
                 {1, 100},
                 {7, 100},
                 {1, 100},
                 {7, 100}},
          .expected{{1, 100}, {7, 100}},
      },
  };

  for (const auto &[items, expected] : test_cases) {
    const auto actual = Solution::highFive(items);
    REQUIRE(expected == actual);
  }
}
