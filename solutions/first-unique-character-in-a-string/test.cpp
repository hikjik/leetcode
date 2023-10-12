#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string s;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .s = "leetcode",
          .expected = 0,
      },
      {
          .s = "loveleetcode",
          .expected = 2,
      },
      {
          .s = "aabb",
          .expected = -1,
      },
  };

  for (const auto &[s, expected] : test_cases) {
    const auto actual = Solution::firstUniqChar(s);
    REQUIRE(expected == actual);
  }
}
