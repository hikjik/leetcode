#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<std::string> strs;
    std::vector<std::vector<std::string>> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .strs{"eat", "tea", "tan", "ate", "nat", "bat"},
          .expected{{"bat"}, {"nat", "tan"}, {"ate", "eat", "tea"}},
      },
      {
          .strs{""},
          .expected{{""}},
      },
      {
          .strs{"a"},
          .expected{{"a"}},
      },
  };

  for (const auto &[strs, expected] : test_cases) {
    auto actual = Solution::groupAnagrams(strs);
    for (auto &a : actual) {
      std::sort(a.begin(), a.end());
    }
    REQUIRE(expected == actual);
  }
}
