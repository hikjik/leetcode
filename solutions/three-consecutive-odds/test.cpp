#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> arr;
    bool expected;
  };

  std::vector<TestCase> test_cases{
      {
          .arr{2, 6, 4, 1},
          .expected = false,
      },
      {
          .arr{1, 2, 34, 3, 4, 5, 7, 23, 12},
          .expected = true,
      },
  };

  for (const auto &[arr, expected] : test_cases) {
    const auto actual = Solution::threeConsecutiveOdds(arr);
    REQUIRE(expected == actual);
  }
}
