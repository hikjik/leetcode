#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string s;
    std::vector<std::vector<std::string>> knowledge;
    std::string expected;
  };

  std::vector<TestCase> test_cases{
      {
          .s = "(name)is(age)yearsold",
          .knowledge{{"name", "bob"}, {"age", "two"}},
          .expected = "bobistwoyearsold",
      },
      {
          .s = "hi(name)",
          .knowledge{{"a", "b"}},
          .expected = "hi?",
      },
      {
          .s = "(a)(a)(a)aaa",
          .knowledge{{"a", "yes"}},
          .expected = "yesyesyesaaa",
      },
  };

  for (const auto &[s, knowledge, expected] : test_cases) {
    const auto actual = Solution::evaluate(s, knowledge);
    REQUIRE(expected == actual);
  }
}
