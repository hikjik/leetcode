#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums;
    bool expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{7, 21, 3},
          .expected = true,
      },
      {
          .nums{5, 2, 6, 2},
          .expected = false,
      },
      {
          .nums{10, 5, 9, 3, 15},
          .expected = true,
      },
  };

  for (const auto &[nums, expected] : test_cases) {
    const auto actual = Solution::gcdSort(nums);
    REQUIRE(expected == actual);
  }
}
