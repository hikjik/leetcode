#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{0, 0, 1, 0, 1, 1, 1, 1},
          .expected = 5,
      },
      {
          .nums{0, 0, 1, 1, 0},
          .expected = 0,
      },
      {
          .nums{1, 0, 1, 0, 1, 0, 1, 0},
          .expected = -1,
      },
  };

  for (const auto &[nums, expected] : test_cases) {
    const int n = nums.size();
    ArrayReader reader(nums);
    const auto actual = Solution::guessMajority(reader);

    if (expected == -1) {
      REQUIRE(-1 == actual);
    } else {
      REQUIRE(0 <= actual);
      REQUIRE(actual < n);
      REQUIRE(nums[expected] == nums[actual]);
      REQUIRE(reader.getNumberOfCalls() <= n);
    }
  }
}
