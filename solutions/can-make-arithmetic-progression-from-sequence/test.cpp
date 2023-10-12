#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> arr;
    bool expected;
  };

  std::vector<TestCase> test_cases{
      {
          .arr{3, 5, 1},
          .expected = true,
      },
      {
          .arr{1, 2, 4},
          .expected = false,
      },
  };

  for (const auto &[arr, expected] : test_cases) {
    const auto actual = Solution::canMakeArithmeticProgression(arr);
    REQUIRE(expected == actual);
  }
}
