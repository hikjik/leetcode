#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums;
    std::vector<int> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{3, 1, 2, 4},
          .expected{2, 4, 3, 1},
      },
      {
          .nums{0},
          .expected{0},
      },
  };

  for (const auto &[nums, expected] : test_cases) {
    const auto actual = Solution::sortArrayByParity(nums);
    REQUIRE(std::is_partitioned(actual.begin(), actual.end(),
                                [](int a) { return a % 2 == 0; }));
  }
}
