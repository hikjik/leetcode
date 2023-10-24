#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> arr;
    std::vector<std::vector<int>> pieces;
    bool expected;
  };

  std::vector<TestCase> test_cases{
      {
          .arr{15, 88},
          .pieces{{88}, {15}},
          .expected = true,
      },
      {
          .arr{49, 18, 16},
          .pieces{{16, 18, 49}},
          .expected = false,
      },
      {
          .arr{91, 4, 64, 78},
          .pieces{{78}, {4, 64}, {91}},
          .expected = true,
      },
  };

  for (const auto &[arr, pieces, expected] : test_cases) {
    const auto actual = Solution::canFormArray(arr, pieces);
    REQUIRE(expected == actual);
  }
}
