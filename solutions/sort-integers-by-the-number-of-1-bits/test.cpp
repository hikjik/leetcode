#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> arr;
    std::vector<int> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .arr{0, 1, 2, 3, 4, 5, 6, 7, 8},
          .expected{0, 1, 2, 4, 8, 3, 5, 6, 7},
      },
      {
          .arr{1024, 512, 256, 128, 64, 32, 16, 8, 4, 2, 1},
          .expected{1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024},
      },
  };

  for (const auto &[arr, expected] : test_cases) {
    const auto actual = Solution::sortByBits(arr);
    REQUIRE(expected == actual);
  }
}
