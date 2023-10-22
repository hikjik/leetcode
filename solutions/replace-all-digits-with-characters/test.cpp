#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string s;
    std::string expected;
  };

  std::vector<TestCase> test_cases{
      {
          .s = "a1c1e1",
          .expected = "abcdef",
      },
      {
          .s = "a1b2c3d4e",
          .expected = "abbdcfdhe",
      },
  };

  for (const auto &[s, expected] : test_cases) {
    const auto actual = Solution::replaceDigits(s);
    REQUIRE(expected == actual);
  }
}
