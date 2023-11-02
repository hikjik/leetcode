#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums;
    std::vector<std::vector<int>> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{1, 2, 2},
          .expected{{}, {1}, {1, 2}, {1, 2, 2}, {2}, {2, 2}},
      },
      {
          .nums{0},
          .expected{{}, {0}},
      },
  };

  for (const auto &[nums, expected] : test_cases) {
    const auto actual = Solution::subsetsWithDup(nums);
    REQUIRE_THAT(expected, Catch::Matchers::UnorderedEquals(actual));
  }
}
