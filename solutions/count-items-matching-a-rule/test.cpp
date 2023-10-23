#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<std::vector<std::string>> items;
    std::string ruleKey;
    std::string ruleValue;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .items{{"phone", "blue", "pixel"},
                 {"computer", "silver", "lenovo"},
                 {"phone", "gold", "iphone"}},
          .ruleKey = "color",
          .ruleValue = "silver",
          .expected = 1,
      },
      {
          .items{{"phone", "blue", "pixel"},
                 {"computer", "silver", "phone"},
                 {"phone", "gold", "iphone"}},
          .ruleKey = "type",
          .ruleValue = "phone",
          .expected = 2,
      },
  };

  for (const auto &[items, ruleKey, ruleValue, expected] : test_cases) {
    const auto actual = Solution::countMatches(items, ruleKey, ruleValue);
    REQUIRE(expected == actual);
  }
}
