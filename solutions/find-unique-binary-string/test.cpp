#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<std::string> nums;
    std::string expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{"01", "10"},
          .expected = "11",
      },
      {
          .nums{"00", "01"},
          .expected = "11",
      },
      {
          .nums{"111", "011", "001"},
          .expected = "101",
      },
  };

  SECTION("Hash Table") {
    for (const auto &[nums, expected] : test_cases) {
      const auto actual = hash_table::Solution::findDifferentBinaryString(nums);
      REQUIRE(expected.size() == actual.size());
      REQUIRE(std::ranges::all_of(actual,
                                  [](char c) { return c == '0' || c == '1'; }));
      REQUIRE(std::find(nums.begin(), nums.end(), actual) == nums.end());
    }
  }

  SECTION("Cantor") {
    for (const auto &[nums, expected] : test_cases) {
      const auto actual = cantor::Solution::findDifferentBinaryString(nums);
      REQUIRE(expected.size() == actual.size());
      REQUIRE(std::ranges::all_of(actual,
                                  [](char c) { return c == '0' || c == '1'; }));
      REQUIRE(std::find(nums.begin(), nums.end(), actual) == nums.end());
    }
  }
}
