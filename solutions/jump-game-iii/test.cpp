#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> arr;
    int start;
    bool expected;
  };

  std::vector<TestCase> test_cases{
      {
          .arr{4, 2, 3, 0, 3, 1, 2},
          .start = 5,
          .expected = true,
      },
      {
          .arr{4, 2, 3, 0, 3, 1, 2},
          .start = 0,
          .expected = true,
      },
      {
          .arr{3, 0, 2, 1, 2},
          .start = 2,
          .expected = false,
      },
  };

  for (const auto &[arr, start, expected] : test_cases) {
    const auto actual = Solution::canReach(arr, start);
    REQUIRE(expected == actual);
  }
}
