#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> digits;
    std::vector<int> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .digits{2, 1, 3, 0},
          .expected{102, 120, 130, 132, 210, 230, 302, 310, 312, 320},
      },
      {
          .digits{2, 2, 8, 8, 2},
          .expected{222, 228, 282, 288, 822, 828, 882},
      },
      {
          .digits{3, 7, 5},
          .expected{},
      },
  };

  for (const auto &[digits, expected] : test_cases) {
    const auto actual = Solution::findEvenNumbers(digits);
    REQUIRE(expected == actual);
  }
}
