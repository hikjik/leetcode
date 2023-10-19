#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string jewels;
    std::string stones;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .jewels = "aA",
          .stones = "aAAbbbb",
          .expected = 3,
      },
      {
          .jewels = "z",
          .stones = "ZZ",
          .expected = 0,
      },
  };

  for (const auto &[jewels, stones, expected] : test_cases) {
    const auto actual = Solution::numJewelsInStones(jewels, stones);
    REQUIRE(expected == actual);
  }
}
