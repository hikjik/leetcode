#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums;
    std::string expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{10, 2},
          .expected = "210",
      },
      {
          .nums{3, 30, 34, 5, 9},
          .expected = "9534330",
      },
      {
          .nums{432, 43243},
          .expected = "43243432",
      },
  };

  for (const auto &[nums, expected] : test_cases) {
    const auto actual = Solution::largestNumber(nums);
    REQUIRE(expected == actual);
  }
}
