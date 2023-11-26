#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<std::vector<int>> mat;
    int k;
    bool expected;
  };

  std::vector<TestCase> test_cases{
      {
          .mat{{1, 2, 1, 2}, {5, 5, 5, 5}, {6, 3, 6, 3}},
          .k = 2,
          .expected = true,
      },
      {
          .mat{{2, 2}, {2, 2}},
          .k = 3,
          .expected = true,
      },
      {
          .mat{{1, 2}},
          .k = 1,
          .expected = false,
      },
  };

  SECTION("STL") {
    for (const auto &[mat, k, expected] : test_cases) {
      const auto actual = stl::Solution::areSimilar(mat, k);
      REQUIRE(expected == actual);
    }
  }

  SECTION("Constant Space") {
    for (const auto &[mat, k, expected] : test_cases) {
      const auto actual = space::Solution::areSimilar(mat, k);
      REQUIRE(expected == actual);
    }
  }
}
