#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<std::string> strings;
    std::vector<std::vector<std::string>> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .strings{"abc", "bcd", "acef", "xyz", "az", "ba", "a", "z"},
          .expected{{"acef"}, {"a", "z"}, {"abc", "bcd", "xyz"}, {"az", "ba"}},
      },
      {
          .strings{"a"},
          .expected{{"a"}},
      },
  };

  for (const auto &[strings, expected] : test_cases) {
    const auto actual = Solution::groupStrings(strings);
    REQUIRE_THAT(expected, Catch::Matchers::UnorderedEquals(actual));
  }
}
