#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<std::vector<int>> accounts;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .accounts{{1, 2, 3}, {3, 2, 1}},
          .expected = 6,
      },
      {
          .accounts{{1, 5}, {7, 3}, {3, 5}},
          .expected = 10,
      },
      {
          .accounts{{2, 8, 7}, {7, 1, 3}, {1, 9, 5}},
          .expected = 17,
      },
  };

  for (const auto &[accounts, expected] : test_cases) {
    const auto actual = Solution::maximumWealth(accounts);
    REQUIRE(expected == actual);
  }
}
