#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string s;
    std::vector<int> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .s = "IDID",
          .expected{0, 4, 1, 3, 2},
      },
      {
          .s = "III",
          .expected{0, 1, 2, 3},
      },
      {
          .s = "DDI",
          .expected{3, 2, 0, 1},
      },
  };

  for (const auto &[s, expected] : test_cases) {
    const auto actual = Solution::diStringMatch(s);
    REQUIRE(expected == actual);
  }
}
