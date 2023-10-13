#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    int turnedOn;
    std::vector<std::string> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .turnedOn = 1,
          .expected{"0:01", "0:02", "0:04", "0:08", "0:16", "0:32", "1:00",
                    "2:00", "4:00", "8:00"},
      },
      {
          .turnedOn = 9,
          .expected{},
      },
  };

  for (const auto &[turnedOn, expected] : test_cases) {
    const auto actual = Solution::readBinaryWatch(turnedOn);
    REQUIRE(expected == actual);
  }
}
