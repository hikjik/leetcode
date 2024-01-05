#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> sweetness;
    int k;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .sweetness{1, 2, 3, 4, 5, 6, 7, 8, 9},
          .k = 5,
          .expected = 6,
      },
      {
          .sweetness{5, 6, 7, 8, 9, 1, 2, 3, 4},
          .k = 8,
          .expected = 1,
      },
      {
          .sweetness{1, 2, 2, 1, 2, 2, 1, 2, 2},
          .k = 2,
          .expected = 5,
      },
  };

  for (const auto &[sweetness, k, expected] : test_cases) {
    const auto actual = Solution::maximizeSweetness(sweetness, k);
    REQUIRE(expected == actual);
  }
}
