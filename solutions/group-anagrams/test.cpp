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

  SECTION("Naive") {
    for (const auto &[strs, expected] : test_cases) {
      auto actual = naive::Solution::groupAnagrams(strs);
      for (auto &a : actual) {
        std::sort(a.begin(), a.end());
      }
      REQUIRE_THAT(expected, Catch::Matchers::UnorderedEquals(actual));
    }
  }

  SECTION("Sorting") {
    for (const auto &[strs, expected] : test_cases) {
      auto actual = sorting::Solution::groupAnagrams(strs);
      for (auto &a : actual) {
        std::sort(a.begin(), a.end());
      }
      REQUIRE_THAT(expected, Catch::Matchers::UnorderedEquals(actual));
    }
  }

  SECTION("Counting") {
    for (const auto &[strs, expected] : test_cases) {
      auto actual = counting::Solution::groupAnagrams(strs);
      for (auto &a : actual) {
        std::sort(a.begin(), a.end());
      }
      REQUIRE_THAT(expected, Catch::Matchers::UnorderedEquals(actual));
    }
  }
}
