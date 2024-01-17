#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> arr;
    std::vector<int> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .arr{6, 2, 3, 4},
          .expected{6, 3, 3, 4},
      },
      {
          .arr{1, 6, 3, 4, 3, 5},
          .expected{1, 4, 4, 4, 4, 5},
      },
  };

  for (const auto &[arr, expected] : test_cases) {
    const auto actual = Solution::transformArray(arr);
    REQUIRE(expected == actual);
  }
}
