#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> arr;
    bool expected;
  };

  std::vector<TestCase> test_cases{
      {
          .arr{0, 2, 1, -6, 6, 7, 9, -1, 2, 0, 1},
          .expected = false,
      },
      {
          .arr{1, -1, 1, -1},
          .expected = false,
      },
      {
          .arr{0, 2, 1, -6, 6, -7, 9, 1, 2, 0, 1},
          .expected = true,
      },
      {
          .arr{3, 3, 6, 5, -2, 2, 5, 1, -9, 4},
          .expected = true,
      },
      {
          .arr{3, 3, 0, 0, 0, 3},
          .expected = true,
      },
  };

  for (const auto &[arr, expected] : test_cases) {
    const auto actual = Solution::canThreePartsEqualSum(arr);
    REQUIRE(expected == actual);
  }
}
