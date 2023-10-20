#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> deck;
    bool expected;
  };

  std::vector<TestCase> test_cases{
      {
          .deck{1, 2, 3, 4, 4, 3, 2, 1},
          .expected = true,
      },
      {
          .deck{1, 1, 1, 2, 2, 2, 3, 3},
          .expected = false,
      },
  };

  for (const auto &[deck, expected] : test_cases) {
    const auto actual = Solution::hasGroupsSizeX(deck);
    REQUIRE(expected == actual);
  }
}
