#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums;
    int val;
    int size;
    std::vector<int> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{3, 2, 2, 3},
          .val = 3,
          .size = 2,
          .expected{2, 2},
      },
      {
          .nums{0, 1, 2, 2, 3, 0, 4, 2},
          .val = 2,
          .size = 5,
          .expected{0, 1, 4, 0, 3},
      },
  };

  SECTION("Two Pointers") {
    for (auto &[nums, val, size, expected] : test_cases) {
      REQUIRE(size == two_pointers::Solution::removeElement(nums, val));
      nums.resize(size);
      REQUIRE_THAT(expected, Catch::Matchers::UnorderedEquals(nums));
    }
  }

  SECTION("STL") {
    for (auto &[nums, val, size, expected] : test_cases) {
      REQUIRE(size == stl::Solution::removeElement(nums, val));
      nums.resize(size);
      REQUIRE_THAT(expected, Catch::Matchers::UnorderedEquals(nums));
    }
  }
}
