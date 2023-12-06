#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<std::string> cpdomains;
    std::vector<std::string> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .cpdomains{"9001 discuss.leetcode.com"},
          .expected{"9001 leetcode.com", "9001 discuss.leetcode.com",
                    "9001 com"},
      },
      {
          .cpdomains{"900 google.mail.com", "50 yahoo.com", "1 intel.mail.com",
                     "5 wiki.org"},
          .expected{"901 mail.com", "50 yahoo.com", "900 google.mail.com",
                    "5 wiki.org", "5 org", "1 intel.mail.com", "951 com"},
      },
  };

  for (const auto &[cpdomains, expected] : test_cases) {
    const auto actual = Solution::subdomainVisits(cpdomains);
    REQUIRE_THAT(expected, Catch::Matchers::UnorderedEquals(actual));
  }
}
