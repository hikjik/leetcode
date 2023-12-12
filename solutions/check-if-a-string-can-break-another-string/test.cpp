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
          .s1 = "abc",
          .s2 = "xya",
          .expected = true,
      },
      {
          .s1 = "abe",
          .s2 = "acd",
          .expected = false,
      },
      {
          .s1 = "leetcodee",
          .s2 = "interview",
          .expected = true,
      },
  };

  for (const auto &[s1, s2, expected] : test_cases) {
    const auto actual = Solution::checkIfCanBreak(s1, s2);
    REQUIRE(expected == actual);
  }
}
