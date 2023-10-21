#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> target;
    std::vector<int> arr;
    bool expected;
  };

  std::vector<TestCase> test_cases{
      {
          .target{1, 2, 3, 4},
          .arr{2, 4, 1, 3},
          .expected = true,
      },
      {
          .target{7},
          .arr{7},
          .expected = true,
      },
      {
          .target{3, 7, 9},
          .arr{3, 7, 11},
          .expected = false,
      },
  };

  for (const auto &[target, arr, expected] : test_cases) {
    const auto actual = Solution::canBeEqual(target, arr);
    REQUIRE(expected == actual);
  }
}
