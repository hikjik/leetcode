#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<std::vector<int>> mat;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .mat{{1, 2, 3, 4, 5},
               {2, 4, 5, 8, 10},
               {3, 5, 7, 9, 11},
               {1, 3, 5, 7, 9}},
          .expected = 5,
      },
      {
          .mat{{1, 2, 3}, {2, 3, 4}, {2, 3, 5}},
          .expected = 2,
      },
  };

  SECTION("Hash Table") {
    for (const auto &[mat, expected] : test_cases) {
      const auto actual = ht::Solution::smallestCommonElement(mat);
      REQUIRE(expected == actual);
    }
  }

  SECTION("Binary Search") {
    for (const auto &[mat, expected] : test_cases) {
      const auto actual = bs::Solution::smallestCommonElement(mat);
      REQUIRE(expected == actual);
    }
  }

  SECTION("Row positions") {
    for (const auto &[mat, expected] : test_cases) {
      const auto actual = rp::Solution::smallestCommonElement(mat);
      REQUIRE(expected == actual);
    }
  }
}
