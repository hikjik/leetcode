#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<std::vector<int>> questions;
    long long expected;
  };

  std::vector<TestCase> test_cases{
      {
          .questions{{3, 2}, {4, 3}, {4, 4}, {2, 5}},
          .expected = 5,
      },
      {
          .questions{{1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5}},
          .expected = 7,
      },
  };

  for (const auto &[questions, expected] : test_cases) {
    const auto actual = Solution::mostPoints(questions);
    REQUIRE(expected == actual);
  }
}
