#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums;
    int size;
    std::vector<int> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{1, 1, 2},
          .size = 2,
          .expected{1, 2},
      },
      {
          .nums{0, 0, 1, 1, 1, 2, 2, 3, 3, 4},
          .size = 5,
          .expected{0, 1, 2, 3, 4},
      },
  };

  SECTION("Two Pointers") {
    for (auto &[nums, size, expected] : test_cases) {
      REQUIRE(size == two_pointers::Solution::removeDuplicates(nums));
      nums.erase(nums.begin() + size, nums.end());
      REQUIRE(expected == nums);
    }
  }

  SECTION("STL") {
    for (auto &[nums, size, expected] : test_cases) {
      REQUIRE(size == stl::Solution::removeDuplicates(nums));
      nums.erase(nums.begin() + size, nums.end());
      REQUIRE(expected == nums);
    }
  }
}
