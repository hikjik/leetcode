#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string s1;
    std::string s2;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .s1 = "sea",
          .s2 = "eat",
          .expected = 231,
      },
      {
          .s1 = "delete",
          .s2 = "leet",
          .expected = 403,
      },
  };

  for (const auto &[s1, s2, expected] : test_cases) {
    const auto actual = Solution::minimumDeleteSum(s1, s2);
    REQUIRE(expected == actual);
  }
}
