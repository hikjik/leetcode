#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string s;
    std::string expected;
  };

  std::vector<TestCase> test_cases{
      {
          .s = "leet**cod*e",
          .expected = "lecoe",
      },
      {
          .s = "erase*****",
          .expected = "",
      },
  };

  for (const auto &[s, expected] : test_cases) {
    const auto actual = Solution::removeStars(s);
    REQUIRE(expected == actual);
  }
}
