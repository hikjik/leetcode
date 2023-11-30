#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> A;
    std::vector<int> B;
    std::vector<int> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .A{1, 3, 2, 4},
          .B{3, 1, 2, 4},
          .expected{0, 2, 3, 4},
      },
      {
          .A{2, 3, 1},
          .B{3, 1, 2},
          .expected{0, 1, 3},
      },
  };

  for (const auto &[A, B, expected] : test_cases) {
    const auto actual = Solution::findThePrefixCommonArray(A, B);
    REQUIRE(expected == actual);
  }
}
