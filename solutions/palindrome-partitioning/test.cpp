#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string s;
    std::vector<std::vector<std::string>> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .s = "aab",
          .expected{{"a", "a", "b"}, {"aa", "b"}},
      },
      {
          .s = "a",
          .expected{{"a"}},
      },
  };

  for (const auto &[s, expected] : test_cases) {
    const auto actual = Solution::partition(s);
    REQUIRE(expected == actual);
  }
}
