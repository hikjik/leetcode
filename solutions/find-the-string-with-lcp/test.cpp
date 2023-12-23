#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<std::vector<int>> lcp;
    std::string expected;
  };

  std::vector<TestCase> test_cases{
      {
          .lcp{{4, 0, 2, 0}, {0, 3, 0, 1}, {2, 0, 2, 0}, {0, 1, 0, 1}},
          .expected = "abab",
      },
      {
          .lcp{{4, 3, 2, 1}, {3, 3, 2, 1}, {2, 2, 2, 1}, {1, 1, 1, 1}},
          .expected = "aaaa",
      },
      {
          .lcp{{4, 3, 2, 1}, {3, 3, 2, 1}, {2, 2, 2, 1}, {1, 1, 1, 3}},
          .expected = "",
      },
      {
          .lcp{{0}},
          .expected = "",
      },
  };

  for (const auto &[lcp, expected] : test_cases) {
    const auto actual = Solution::findTheString(lcp);
    REQUIRE(expected == actual);
  }
}
