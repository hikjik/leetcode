#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums;
    int k;
    int p;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{2, 3, 3, 2, 2},
          .k = 2,
          .p = 2,
          .expected = 11,
      },
      {
          .nums{1, 2, 3, 4},
          .k = 4,
          .p = 1,
          .expected = 10,
      },
  };

  SECTION("Trie") {
    for (const auto &[nums, k, p, expected] : test_cases) {
      const auto actual = trie::Solution::countDistinct(nums, k, p);
      REQUIRE(expected == actual);
    }
  }

  SECTION("Rolling Hash") {
    for (const auto &[nums, k, p, expected] : test_cases) {
      const auto actual = hash::Solution::countDistinct(nums, k, p);
      REQUIRE(expected == actual);
    }
  }
}
