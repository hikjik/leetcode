#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> arr;
    std::vector<int> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .arr{17, 18, 5, 4, 6, 1},
          .expected{18, 6, 6, 6, 1, -1},
      },
      {
          .arr{400},
          .expected{-1},
      },
  };

  for (const auto &[arr, expected] : test_cases) {
    const auto actual = Solution::replaceElements(arr);
    REQUIRE(expected == actual);
  }
}
