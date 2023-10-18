#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<std::string> details;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .details{"7868190130M7522", "5303914400F9211", "9273338290F4010"},
          .expected = 2,
      },
      {
          .details{"1313579440F2036", "2921522980M5644"},
          .expected = 0,
      },
  };

  for (const auto &[details, expected] : test_cases) {
    const auto actual = Solution::countSeniors(details);
    REQUIRE(expected == actual);
  }
}
