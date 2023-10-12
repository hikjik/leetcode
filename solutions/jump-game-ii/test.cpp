#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{2, 3, 1, 1, 4},
          .expected = 2,
      },
      {
          .nums{2, 3, 0, 1, 4},
          .expected = 2,
      },
  };

  for (const auto &[nums, expected] : test_cases) {
    const auto actual = Solution::jump(nums);
    REQUIRE(expected == actual);
  }
}
