#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<char> letters;
    char target;
    char expected;
  };

  std::vector<TestCase> test_cases{
      {
          .letters{'c', 'f', 'j'},
          .target = 'a',
          .expected = 'c',
      },
      {
          .letters{'c', 'f', 'j'},
          .target = 'c',
          .expected = 'f',
      },
      {
          .letters{'x', 'x', 'y', 'y'},
          .target = 'z',
          .expected = 'x',
      },
  };

  for (const auto &[letters, target, expected] : test_cases) {
    const auto actual = Solution::nextGreatestLetter(letters, target);
    REQUIRE(expected == actual);
  }
}
