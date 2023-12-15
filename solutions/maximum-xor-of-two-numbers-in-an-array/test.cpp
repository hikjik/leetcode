#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{3, 10, 5, 25, 2, 8},
          .expected = 28,
      },
      {
          .nums{14, 70, 53, 83, 49, 91, 36, 80, 92, 51, 66, 70},
          .expected = 127,
      },
      {
          .nums{0},
          .expected = 0,
      },
  };

  SECTION("Bit Trie") {
    for (const auto &[nums, expected] : test_cases) {
      const auto actual = bit_trie::Solution::findMaximumXOR(nums);
      REQUIRE(expected == actual);
    }
  }

  SECTION("Hast Table") {
    for (const auto &[nums, expected] : test_cases) {
      const auto actual = hash_table::Solution::findMaximumXOR(nums);
      REQUIRE(expected == actual);
    }
  }
}
