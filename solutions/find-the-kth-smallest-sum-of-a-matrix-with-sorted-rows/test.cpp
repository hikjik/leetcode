#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<std::vector<int>> mat;
    int k;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .mat{{1, 3, 11}, {2, 4, 6}},
          .k = 5,
          .expected = 7,
      },
      {
          .mat{{1, 3, 11}, {2, 4, 6}},
          .k = 9,
          .expected = 17,
      },
      {
          .mat{{1, 10, 10}, {1, 4, 5}, {2, 3, 6}},
          .k = 7,
          .expected = 9,
      },
  };

  for (const auto &[mat, k, expected] : test_cases) {
    const auto actual = Solution::kthSmallest(mat, k);
    REQUIRE(expected == actual);
  }
}
