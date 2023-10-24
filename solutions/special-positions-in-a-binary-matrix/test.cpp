#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<std::vector<int>> mat;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .mat{{1, 0, 0}, {0, 0, 1}, {1, 0, 0}},
          .expected = 1,
      },
      {
          .mat{{1, 0, 0}, {0, 1, 0}, {0, 0, 1}},
          .expected = 3,
      },
  };

  for (const auto &[mat, expected] : test_cases) {
    const auto actual = Solution::numSpecial(mat);
    REQUIRE(expected == actual);
  }
}
