#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> arr;
    int m;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .arr{3, 5, 1, 2, 4},
          .m = 1,
          .expected = 4,
      },
      {
          .arr{3, 1, 5, 4, 2},
          .m = 2,
          .expected = -1,
      },
  };

  for (const auto &[arr, m, expected] : test_cases) {
    const auto actual = Solution::findLatestStep(arr, m);
    REQUIRE(expected == actual);
  }
}
