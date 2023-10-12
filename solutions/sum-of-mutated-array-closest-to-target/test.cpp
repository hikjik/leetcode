#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> arr;
    int target;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .arr{4, 9, 3},
          .target = 10,
          .expected = 3,
      },
      {
          .arr{2, 3, 5},
          .target = 10,
          .expected = 5,
      },
      {
          .arr{60864, 25176, 27249, 21296, 20204},
          .target = 56803,
          .expected = 11361,
      },
  };

  for (const auto &[arr, target, expected] : test_cases) {
    const auto actual = Solution::findBestValue(arr, target);
    REQUIRE(expected == actual);
  }
}
