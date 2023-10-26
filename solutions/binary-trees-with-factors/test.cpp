#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> arr;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .arr{2, 4, 5, 10},
          .expected = 7,
      },
      {
          .arr{2, 4},
          .expected = 3,
      },
  };

  for (const auto &[arr, expected] : test_cases) {
    const auto actual = Solution::numFactoredBinaryTrees(arr);
    REQUIRE(expected == actual);
  }
}
