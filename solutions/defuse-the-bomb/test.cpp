#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> code;
    int k;
    std::vector<int> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .code{5, 7, 1, 4},
          .k = 3,
          .expected{12, 10, 16, 13},
      },
      {
          .code{1, 2, 3, 4},
          .k = 0,
          .expected{0, 0, 0, 0},
      },
      {
          .code{2, 4, 9, 3},
          .k = -2,
          .expected{12, 5, 6, 13},
      },
  };

  for (const auto &[code, k, expected] : test_cases) {
    const auto actual = Solution::decrypt(code, k);
    REQUIRE(expected == actual);
  }
}
