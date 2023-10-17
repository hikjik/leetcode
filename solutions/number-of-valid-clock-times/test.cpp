#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string time;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .time = "0?:0?",
          .expected = 100,
      },
      {
          .time = "?5:00",
          .expected = 2,
      },
      {
          .time = "??:??",
          .expected = 1440,
      },
  };

  for (const auto &[time, expected] : test_cases) {
    const auto actual = Solution::countTime(time);
    REQUIRE(expected == actual);
  }
}
