#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums;
    long long expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{12, 6, 1, 2, 7},
          .expected = 77,
      },
      {
          .nums{1, 10, 3, 4, 19},
          .expected = 133,
      },
      {
          .nums{1, 2, 3},
          .expected = 0,
      },
  };

  for (const auto &[nums, expected] : test_cases) {
    const auto actual = Solution::maximumTripletValue(nums);
    REQUIRE(expected == actual);
  }
}
