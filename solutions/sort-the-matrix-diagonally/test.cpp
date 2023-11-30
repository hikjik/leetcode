#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<std::vector<int>> mat;
    std::vector<std::vector<int>> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .mat{{3, 3, 1, 1}, {2, 2, 1, 2}, {1, 1, 1, 2}},
          .expected{{1, 1, 1, 1}, {1, 2, 2, 2}, {1, 2, 3, 3}},
      },
      {
          .mat{{11, 25, 66, 1, 69, 7},
               {23, 55, 17, 45, 15, 52},
               {75, 31, 36, 44, 58, 8},
               {22, 27, 33, 25, 68, 4},
               {84, 28, 14, 11, 5, 50}},
          .expected{{5, 17, 4, 1, 52, 7},
                    {11, 11, 25, 45, 8, 69},
                    {14, 23, 25, 44, 58, 15},
                    {22, 27, 31, 36, 50, 66},
                    {84, 28, 75, 33, 55, 68}},
      },
  };

  SECTION("Hash Table") {
    for (const auto &[mat, expected] : test_cases) {
      const auto actual = hash_table::Solution::diagonalSort(mat);
      REQUIRE(expected == actual);
    }
  }

  SECTION("Straight Forward") {
    for (const auto &[mat, expected] : test_cases) {
      const auto actual = optimized::Solution::diagonalSort(mat);
      REQUIRE(expected == actual);
    }
  }
}
