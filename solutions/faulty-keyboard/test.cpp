#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string s;
    std::string expected;
  };

  std::vector<TestCase> test_cases{
      {
          .s = "string",
          .expected = "rtsng",
      },
      {
          .s = "poiinter",
          .expected = "ponter",
      },
  };

  for (const auto &[s, expected] : test_cases) {
    const auto actual = Solution::finalString(s);
    REQUIRE(expected == actual);
  }
}
