#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{3, 5, 2, 4},
          .expected = 2,
      },
      {
          .nums{9, 2, 5, 4},
          .expected = 4,
      },
      {
          .nums{7, 6, 8},
          .expected = 0,
      },
  };

  for (const auto &[nums, expected] : test_cases) {
    const auto actual = Solution::maxNumOfMarkedIndices(nums);
    REQUIRE(expected == actual);
  }
}
