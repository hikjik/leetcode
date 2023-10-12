#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<std::string> strs;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .strs{"tars", "rats", "arts", "star"},
          .expected = 2,
      },
      {
          .strs{"omv", "ovm"},
          .expected = 1,
      },
  };

  for (const auto &[strs, expected] : test_cases) {
    const auto actual = Solution::numSimilarGroups(strs);
    REQUIRE(expected == actual);
  }
}
