#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums;
    std::vector<std::vector<int>> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{1, 2, 3},
          .expected{
              {1, 2, 3}, {1, 3, 2}, {2, 1, 3}, {2, 3, 1}, {3, 1, 2}, {3, 2, 1}},
      },
      {
          .nums{0, 1},
          .expected{{0, 1}, {1, 0}},
      },
      {
          .nums{1},
          .expected{{1}},
      },
  };

  SECTION("Backtracking") {
    for (const auto &[nums, expected] : test_cases) {
      const auto actual = backtracking::Solution::permute(nums);
      REQUIRE(expected == actual);
    }
  }

  SECTION("STL") {
    for (const auto &[nums, expected] : test_cases) {
      const auto actual = stl::Solution::permute(nums);
      REQUIRE(expected == actual);
    }
  }
}
