#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string s;
    std::vector<std::vector<int>> pairs;
    std::string expected;
  };

  std::vector<TestCase> test_cases{
      {
          .s = "dcab",
          .pairs{{0, 3}, {1, 2}},
          .expected = "bacd",
      },
      {
          .s = "dcab",
          .pairs{{0, 3}, {1, 2}, {0, 2}},
          .expected = "abcd",
      },
      {
          .s = "cba",
          .pairs{{0, 1}, {1, 2}},
          .expected = "abc",
      },
  };

  for (const auto &[s, pairs, expected] : test_cases) {
    const auto actual = Solution::smallestStringWithSwaps(s, pairs);
    REQUIRE(expected == actual);
  }
}
