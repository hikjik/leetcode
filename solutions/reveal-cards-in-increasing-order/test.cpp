#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> deck;
    std::vector<int> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .deck{17, 13, 11, 2, 3, 5, 7},
          .expected{2, 13, 3, 11, 5, 17, 7},
      },
      {
          .deck{1, 1000},
          .expected{1, 1000},
      },
  };

  SECTION("Queue") {
    for (const auto &[deck, expected] : test_cases) {
      const auto actual = queue::Solution::deckRevealedIncreasing(deck);
      REQUIRE(expected == actual);
    }
  }

  SECTION("Deque") {
    for (const auto &[deck, expected] : test_cases) {
      const auto actual = deque::Solution::deckRevealedIncreasing(deck);
      REQUIRE(expected == actual);
    }
  }
}
