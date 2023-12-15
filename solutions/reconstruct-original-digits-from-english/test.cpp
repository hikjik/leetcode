#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string s;
    std::string expected;
  };

  std::vector<TestCase> test_cases{
      {
          .s = "owoztneoer",
          .expected = "012",
      },
      {
          .s = "fviefuro",
          .expected = "45",
      },
  };

  for (const auto &[s, expected] : test_cases) {
    const auto actual = Solution::originalDigits(s);
    REQUIRE(expected == actual);
  }
}
