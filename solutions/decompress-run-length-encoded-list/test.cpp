#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums;
    std::vector<int> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{1, 2, 3, 4},
          .expected{2, 4, 4, 4},
      },
      {
          .nums{1, 1, 2, 3},
          .expected{1, 3, 3},
      },
  };

  for (const auto &[nums, expected] : test_cases) {
    const auto actual = Solution::decompressRLElist(nums);
    REQUIRE(expected == actual);
  }
}
