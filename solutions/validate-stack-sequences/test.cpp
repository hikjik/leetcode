#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> pushed;
    std::vector<int> popped;
    bool expected;
  };

  std::vector<TestCase> test_cases{
      {
          .pushed{1, 2, 3, 4, 5},
          .popped{4, 5, 3, 2, 1},
          .expected = true,
      },
      {
          .pushed{1, 2, 3, 4, 5},
          .popped{4, 3, 5, 1, 2},
          .expected = false,
      },
  };

  for (const auto &[pushed, popped, expected] : test_cases) {
    const auto actual = Solution::validateStackSequences(pushed, popped);
    REQUIRE(expected == actual);
  }
}
