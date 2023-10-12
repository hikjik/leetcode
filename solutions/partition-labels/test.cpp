#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string s;
    std::vector<int> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .s = "ababcbacadefegdehijhklij",
          .expected{9, 7, 8},
      },
      {
          .s = "eccbbbbdec",
          .expected{10},
      },
  };

  for (const auto &[s, expected] : test_cases) {
    const auto actual = Solution::partitionLabels(s);
    REQUIRE(expected == actual);
  }
}
