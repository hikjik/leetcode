#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string s;
    std::vector<std::string> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .s = "25525511135",
          .expected{"255.255.11.135", "255.255.111.35"},
      },
      {
          .s = "0000",
          .expected{"0.0.0.0"},
      },
      {
          .s = "101023",
          .expected{"1.0.10.23", "1.0.102.3", "10.1.0.23", "10.10.2.3",
                    "101.0.2.3"},
      },
  };

  for (const auto &[s, expected] : test_cases) {
    const auto actual = Solution::restoreIpAddresses(s);
    REQUIRE(expected == actual);
  }
}
