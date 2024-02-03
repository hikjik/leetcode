#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums;
    std::string expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{3, 3, 3},
          .expected = "equilateral",
      },
      {
          .nums{3, 4, 5},
          .expected = "scalene",
      },
  };

  for (const auto &[nums, expected] : test_cases) {
    const auto actual = Solution::triangleType(nums);
    REQUIRE(expected == actual);
  }
}
