#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string s;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .s = "zzazz",
          .expected = 0,
      },
      {
          .s = "mbadm",
          .expected = 2,
      },
      {
          .s = "leetcode",
          .expected = 5,
      },
  };

  for (const auto &[s, expected] : test_cases) {
    const auto actual = Solution::minInsertions(s);
    REQUIRE(expected == actual);
  }
}
