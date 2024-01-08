#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string s;
    std::vector<std::vector<int>> shift;
    std::string expected;
  };

  std::vector<TestCase> test_cases{
      {
          .s = "abc",
          .shift{{0, 1}, {1, 2}},
          .expected = "cab",
      },
      {
          .s = "abcdefg",
          .shift{{1, 1}, {1, 1}, {0, 2}, {1, 3}},
          .expected = "efgabcd",
      },
      {
          .s = "abcdefg",
          .shift{{1, 1}, {1, 1}, {0, 2}},
          .expected = "abcdefg",
      },
      {
          .s = "wpdhhcj",
          .shift{{0, 7}, {1, 7}, {1, 0}, {1, 3}, {0, 3}, {0, 6}, {1, 2}},
          .expected = "hcjwpdh",
      },
  };

  for (const auto &[s, shift, expected] : test_cases) {
    const auto actual = Solution::stringShift(s, shift);
    REQUIRE(expected == actual);
  }
}
