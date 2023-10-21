#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<std::string> emails;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .emails{"test.email+alex@leetcode.com",
                  "test.e.mail+bob.cathy@leetcode.com",
                  "testemail+david@lee.tcode.com"},
          .expected = 2,
      },
      {
          .emails{"a@leetcode.com", "b@leetcode.com", "c@leetcode.com"},
          .expected = 3,
      },
  };

  for (const auto &[emails, expected] : test_cases) {
    const auto actual = Solution::numUniqueEmails(emails);
    REQUIRE(expected == actual);
  }
}
