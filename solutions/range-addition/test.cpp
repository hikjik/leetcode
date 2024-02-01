#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    int length;
    std::vector<std::vector<int>> updates;
    std::vector<int> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .length = 5,
          .updates{{1, 3, 2}, {2, 4, 3}, {0, 2, -2}},
          .expected{-2, 0, 3, 5, 3},
      },
      {
          .length = 10,
          .updates{{2, 4, 6}, {5, 6, 8}, {1, 9, -4}},
          .expected{0, -4, 2, 2, 2, 4, 4, -4, -4, -4},
      },
  };

  for (const auto &[length, updates, expected] : test_cases) {
    const auto actual = Solution::getModifiedArray(length, updates);
    REQUIRE(expected == actual);
  }
}
