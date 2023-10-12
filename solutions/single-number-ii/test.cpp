#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{2, 2, 3, 2},
          .expected = 3,
      },
      {
          .nums{0, 1, 0, 1, 0, 1, 99},
          .expected = 99,
      },
  };

  for (const auto &[nums, expected] : test_cases) {
    const auto actual = Solution::singleNumber(nums);
    REQUIRE(expected == actual);
  }
}
