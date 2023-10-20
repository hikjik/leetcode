#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums;
    int key;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{1, 100, 200, 1, 100},
          .key = 1,
          .expected = 100,
      },
      {
          .nums{2, 2, 2, 2, 3},
          .key = 2,
          .expected = 2,
      },
  };

  for (const auto &[nums, key, expected] : test_cases) {
    const auto actual = Solution::mostFrequent(nums, key);
    REQUIRE(expected == actual);
  }
}
