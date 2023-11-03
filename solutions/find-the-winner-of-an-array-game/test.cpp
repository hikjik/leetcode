#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> arr;
    int k;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .arr{2, 1, 3, 5, 4, 6, 7},
          .k = 2,
          .expected = 5,
      },
      {
          .arr{3, 2, 1},
          .k = 10,
          .expected = 3,
      },
  };

  for (const auto &[arr, k, expected] : test_cases) {
    const auto actual = Solution::getWinner(arr, k);
    REQUIRE(expected == actual);
  }
}
