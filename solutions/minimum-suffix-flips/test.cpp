#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string target;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .target = "10111",
          .expected = 3,
      },
      {
          .target = "101",
          .expected = 3,
      },
      {
          .target = "00000",
          .expected = 0,
      },
  };

  for (const auto &[target, expected] : test_cases) {
    const auto actual = Solution::minFlips(target);
    REQUIRE(expected == actual);
  }
}
