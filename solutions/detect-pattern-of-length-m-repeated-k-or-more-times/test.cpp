#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> arr;
    int m;
    int k;
    bool expected;
  };

  std::vector<TestCase> test_cases{
      {
          .arr{1, 2, 4, 4, 4, 4},
          .m = 1,
          .k = 3,
          .expected = true,
      },
      {
          .arr{1, 2, 1, 2, 1, 1, 1, 3},
          .m = 2,
          .k = 2,
          .expected = true,
      },
      {
          .arr{1, 2, 1, 2, 1, 3},
          .m = 2,
          .k = 3,
          .expected = false,
      },
  };

  for (const auto &[arr, m, k, expected] : test_cases) {
    const auto actual = Solution::containsPattern(arr, m, k);
    REQUIRE(expected == actual);
  }
}
