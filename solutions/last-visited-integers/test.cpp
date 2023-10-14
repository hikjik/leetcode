#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<std::string> words;
    std::vector<int> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .words{"1", "2", "prev", "prev", "prev"},
          .expected{2, 1, -1},
      },
      {
          .words{"1", "prev", "2", "prev", "prev"},
          .expected{1, 2, 1},
      },
      {
          .words{"prev", "2", "prev", "prev"},
          .expected{-1, 2, -1},
      },
  };

  for (const auto &[words, expected] : test_cases) {
    const auto actual = Solution::lastVisitedIntegers(words);
    REQUIRE(expected == actual);
  }
}
