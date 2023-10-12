#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> parent;
    std::string s;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .parent{-1, 0, 0, 1, 1, 2},
          .s = "abacbe",
          .expected = 3,
      },
      {
          .parent{-1, 0, 0, 0},
          .s = "aabc",
          .expected = 3,
      },
  };

  for (const auto &[parent, s, expected] : test_cases) {
    const auto actual = Solution::longestPath(parent, s);
    REQUIRE(expected == actual);
  }
}
