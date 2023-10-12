#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<std::vector<int>> mat;
    int threshold;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .mat{{1, 1, 3, 2, 4, 3, 2},
               {1, 1, 3, 2, 4, 3, 2},
               {1, 1, 3, 2, 4, 3, 2}},
          .threshold = 4,
          .expected = 2,
      },
      {
          .mat{{2, 2, 2, 2, 2},
               {2, 2, 2, 2, 2},
               {2, 2, 2, 2, 2},
               {2, 2, 2, 2, 2},
               {2, 2, 2, 2, 2}},
          .threshold = 1,
          .expected = 0,
      },
  };

  for (const auto &[mat, threshold, expected] : test_cases) {
    const auto actual = Solution::maxSideLength(mat, threshold);
    REQUIRE(expected == actual);
  }
}
