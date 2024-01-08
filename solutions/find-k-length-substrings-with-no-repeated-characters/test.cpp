#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string s;
    int k;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .s = "havefunonleetcode",
          .k = 5,
          .expected = 6,
      },
      {
          .s = "home",
          .k = 5,
          .expected = 0,
      },
  };

  for (const auto &[s, k, expected] : test_cases) {
    const auto actual = Solution::numKLenSubstrNoRepeats(s, k);
    REQUIRE(expected == actual);
  }
}
