#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> arr;
    bool expected;
  };

  std::vector<TestCase> test_cases{
      {
          .arr{2, 1},
          .expected = false,
      },
      {
          .arr{3, 5, 5},
          .expected = false,
      },
      {
          .arr{0, 3, 2, 1},
          .expected = true,
      },
  };

  for (const auto &[arr, expected] : test_cases) {
    const auto actual = Solution::validMountainArray(arr);
    REQUIRE(expected == actual);
  }
}
