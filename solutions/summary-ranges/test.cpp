#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums;
    std::vector<std::string> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{0, 1, 2, 4, 5, 7},
          .expected{"0->2", "4->5", "7"},
      },
      {
          .nums{0, 2, 3, 4, 6, 8, 9},
          .expected{"0", "2->4", "6", "8->9"},
      },
  };

  for (const auto &[nums, expected] : test_cases) {
    const auto actual = Solution::summaryRanges(nums);
    REQUIRE(expected == actual);
  }
}
