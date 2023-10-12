#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> arr;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .arr{100, -23, -23, 404, 100, 23, 23, 23, 3, 404},
          .expected = 3,
      },
      {
          .arr{7},
          .expected = 0,
      },
      {
          .arr{7, 6, 9, 6, 9, 6, 9, 7},
          .expected = 1,
      },
  };

  for (const auto &[arr, expected] : test_cases) {
    const auto actual = Solution::minJumps(arr);
    REQUIRE(expected == actual);
  }
}
