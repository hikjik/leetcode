#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<std::vector<int>> mat;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .mat{{1, 1}, {9, 9}, {1, 1}},
          .expected = 19,
      },
      {
          .mat{{7}},
          .expected = -1,
      },
      {
          .mat{{9, 7, 8}, {4, 6, 5}, {2, 8, 6}},
          .expected = 97,
      },
  };

  for (const auto &[mat, expected] : test_cases) {
    const auto actual = Solution::mostFrequentPrime(mat);
    REQUIRE(expected == actual);
  }
}
