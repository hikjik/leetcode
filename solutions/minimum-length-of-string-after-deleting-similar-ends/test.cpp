#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string s;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .s = "ca",
          .expected = 2,
      },
      {
          .s = "cabaabac",
          .expected = 0,
      },
      {
          .s = "aabccabba",
          .expected = 3,
      },
  };

  for (const auto &[s, expected] : test_cases) {
    const auto actual = Solution::minimumLength(s);
    REQUIRE(expected == actual);
  }
}
