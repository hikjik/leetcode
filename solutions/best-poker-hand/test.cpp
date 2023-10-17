#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> ranks;
    std::vector<char> suits;
    std::string expected;
  };

  std::vector<TestCase> test_cases{
      {
          .ranks{13, 2, 3, 1, 9},
          .suits{'a', 'a', 'a', 'a', 'a'},
          .expected = "Flush",
      },
      {
          .ranks{4, 4, 2, 4, 4},
          .suits{'d', 'a', 'a', 'b', 'c'},
          .expected = "Three of a Kind",
      },
      {
          .ranks{10, 10, 2, 12, 9},
          .suits{'a', 'b', 'c', 'a', 'd'},
          .expected = "Pair",
      },
  };

  for (const auto &[ranks, suits, expected] : test_cases) {
    const auto actual = Solution::bestHand(ranks, suits);
    REQUIRE(expected == actual);
  }
}
