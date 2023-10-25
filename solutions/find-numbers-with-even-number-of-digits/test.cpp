#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{12, 345, 2, 6, 7896},
          .expected = 2,
      },
      {
          .nums{555, 901, 482, 1771},
          .expected = 1,
      },
  };

  for (const auto &[nums, expected] : test_cases) {
    const auto actual = Solution::findNumbers(nums);
    REQUIRE(expected == actual);
  }
}
