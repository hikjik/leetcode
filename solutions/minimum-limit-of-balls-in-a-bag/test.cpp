#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums;
    int maxOperations;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{9},
          .maxOperations = 2,
          .expected = 3,
      },
      {
          .nums{2, 4, 8, 2},
          .maxOperations = 4,
          .expected = 2,
      },
  };

  for (const auto &[nums, maxOperations, expected] : test_cases) {
    const auto actual = Solution::minimumSize(nums, maxOperations);
    REQUIRE(expected == actual);
  }
}
