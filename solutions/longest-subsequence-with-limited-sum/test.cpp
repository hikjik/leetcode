#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums;
    std::vector<int> queries;
    std::vector<int> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{4, 5, 2, 1},
          .queries{3, 10, 21},
          .expected{2, 3, 4},
      },
      {
          .nums{2, 3, 4, 5},
          .queries{1},
          .expected{0},
      },
  };

  for (const auto &[nums, queries, expected] : test_cases) {
    const auto actual = Solution::answerQueries(nums, queries);
    REQUIRE(expected == actual);
  }
}
