#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> arr;
    bool expected;
  };

  std::vector<TestCase> test_cases{
      {
          .arr{1, 2, 2, 1, 1, 3},
          .expected = true,
      },
      {
          .arr{1, 2},
          .expected = false,
      },
      {
          .arr{-3, 0, 1, -3, 1, 1, 1, -3, 10, 0},
          .expected = true,
      },
  };

  for (const auto &[arr, expected] : test_cases) {
    const auto actual = Solution::uniqueOccurrences(arr);
    REQUIRE(expected == actual);
  }
}
