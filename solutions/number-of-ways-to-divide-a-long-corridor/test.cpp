#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string corridor;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .corridor = "SSPPSPS",
          .expected = 3,
      },
      {
          .corridor = "PPSPSP",
          .expected = 1,
      },
      {
          .corridor = "S",
          .expected = 0,
      },
      {
          .corridor = "SPPSSSSPPS",
          .expected = 1,
      },
  };

  for (const auto &[corridor, expected] : test_cases) {
    const auto actual = Solution::numberOfWays(corridor);
    REQUIRE(expected == actual);
  }
}
