#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> arr;
    int a;
    int b;
    int c;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .arr{3, 0, 1, 1, 9, 7},
          .a = 7,
          .b = 2,
          .c = 3,
          .expected = 4,
      },
      {
          .arr{1, 1, 2, 2, 3},
          .a = 0,
          .b = 0,
          .c = 1,
          .expected = 0,
      },
  };

  for (const auto &[arr, a, b, c, expected] : test_cases) {
    const auto actual = Solution::countGoodTriplets(arr, a, b, c);
    REQUIRE(expected == actual);
  }
}
