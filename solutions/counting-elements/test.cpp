#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> arr;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .arr{1, 2, 3},
          .expected = 2,
      },
      {
          .arr{1, 1, 3, 3, 5, 5, 7, 7},
          .expected = 0,
      },
  };

  for (const auto &[arr, expected] : test_cases) {
    const auto actual = Solution::countElements(arr);
    REQUIRE(expected == actual);
  }
}
