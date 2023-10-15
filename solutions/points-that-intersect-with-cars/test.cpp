#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<std::vector<int>> nums;
    int expected;
  };

  std::vector<TestCase> test_cases{
      // {
      //     .nums{{3, 6}, {1, 5}, {4, 7}},
      //     .expected = 7,
      // },
      // {
      //     .nums{{1, 3}, {5, 8}},
      //     .expected = 7,
      // },
      {
          .nums{{4, 4}, {9, 10}, {9, 10}, {3, 8}},
          .expected = 8,
      },
  };

  for (const auto &[nums, expected] : test_cases) {
    const auto actual = Solution::numberOfPoints(nums);
    REQUIRE(expected == actual);
  }
}
