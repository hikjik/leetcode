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
          .s1 = "bank",
          .s2 = "kanb",
          .expected = true,
      },
      {
          .s1 = "attack",
          .s2 = "defend",
          .expected = false,
      },
      {
          .s1 = "kelb",
          .s2 = "kelb",
          .expected = true,
      },
  };

  for (const auto &[s1, s2, expected] : test_cases) {
    const auto actual = Solution::areAlmostEqual(s1, s2);
    REQUIRE(expected == actual);
  }
}
