#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string num;
    std::string expected;
  };

  std::vector<TestCase> test_cases{
      {
          .num = "257",
          .expected = "IOI",
      },
      {
          .num = "3",
          .expected = "ERROR",
      },
  };

  for (const auto &[num, expected] : test_cases) {
    const auto actual = Solution::toHexspeak(num);
    REQUIRE(expected == actual);
  }
}
