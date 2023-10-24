#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> arr;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .arr{2, 2, 3, 4},
          .expected = 2,
      },
      {
          .arr{1, 2, 2, 3, 3, 3},
          .expected = 3,
      },
      {
          .arr{2, 2, 2, 3, 3},
          .expected = -1,
      },
  };

  for (const auto &[arr, expected] : test_cases) {
    const auto actual = Solution::findLucky(arr);
    REQUIRE(expected == actual);
  }
}
