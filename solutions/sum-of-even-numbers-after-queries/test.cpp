#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums;
    std::vector<std::vector<int>> queries;
    std::vector<int> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{1, 2, 3, 4},
          .queries{{1, 0}, {-3, 1}, {-4, 0}, {2, 3}},
          .expected{8, 6, 2, 4},
      },
      {
          .nums{1},
          .queries{{4, 0}},
          .expected{0},
      },
  };

  for (const auto &[nums, queries, expected] : test_cases) {
    const auto actual = Solution::sumEvenAfterQueries(nums, queries);
    REQUIRE(expected == actual);
  }
}
