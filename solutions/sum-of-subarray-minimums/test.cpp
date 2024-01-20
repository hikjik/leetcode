#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> arr;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .arr{3, 1, 2, 4},
          .expected = 17,
      },
      {
          .arr{11, 81, 94, 43, 3},
          .expected = 444,
      },
  };

  for (const auto &[arr, expected] : test_cases) {
    const auto actual = Solution::sumSubarrayMins(arr);
    REQUIRE(expected == actual);
  }
}
