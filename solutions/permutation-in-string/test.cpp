#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string s1;
    std::string s2;
    bool expected;
  };

  std::vector<TestCase> test_cases{
      {
          .s1 = "ab",
          .s2 = "eidbaooo",
          .expected = true,
      },
      {
          .s1 = "ab",
          .s2 = "eidboaoo",
          .expected = false,
      },
  };

  for (const auto &[s1, s2, expected] : test_cases) {
    const auto actual = Solution::checkInclusion(s1, s2);
    REQUIRE(expected == actual);
  }
}
