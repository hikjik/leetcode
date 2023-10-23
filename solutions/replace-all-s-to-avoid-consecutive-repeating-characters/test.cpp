#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string s;
    std::string expected;
  };

  std::vector<TestCase> test_cases{
      {
          .s = "j?qg??b",
          .expected = "jaqgacb",
      },
      {
          .s = "?zs",
          .expected = "azs",
      },
      {
          .s = "ubv?w",
          .expected = "ubvaw",
      },
  };

  for (const auto &[s, expected] : test_cases) {
    const auto actual = Solution::modifyString(s);
    REQUIRE(expected == actual);
  }
}
