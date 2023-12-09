#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums;
    int maximumBit;
    std::vector<int> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{0, 1, 1, 3},
          .maximumBit = 2,
          .expected{0, 3, 2, 3},
      },
      {
          .nums{2, 3, 4, 7},
          .maximumBit = 3,
          .expected{5, 2, 6, 5},
      },
      {
          .nums{0, 1, 2, 2, 5, 7},
          .maximumBit = 3,
          .expected{4, 3, 6, 4, 6, 7},
      },
  };

  for (const auto &[nums, maximumBit, expected] : test_cases) {
    const auto actual = Solution::getMaximumXor(nums, maximumBit);
    REQUIRE(expected == actual);
  }
}
