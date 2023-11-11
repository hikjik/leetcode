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

  SECTION("Count bits") {
    for (const auto &[nums, expected] : test_cases) {
      const auto actual = count_bits::Solution::singleNumber(nums);
      REQUIRE(expected == actual);
    }
  }

  SECTION("Tricky") {
    for (const auto &[nums, expected] : test_cases) {
      const auto actual = tricky::Solution::singleNumber(nums);
      REQUIRE(expected == actual);
    }
  }
}
