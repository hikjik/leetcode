#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string time;
    std::string expected;
  };

  std::vector<TestCase> test_cases{
      {
          .time = "2?:?0",
          .expected = "23:50",
      },
      {
          .time = "0?:3?",
          .expected = "09:39",
      },
      {
          .time = "1?:22",
          .expected = "19:22",
      },
  };

  for (const auto &[time, expected] : test_cases) {
    const auto actual = Solution::maximumTime(time);
    REQUIRE(expected == actual);
  }
}
