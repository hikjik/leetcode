#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> releaseTimes;
    std::string keysPressed;
    char expected;
  };

  std::vector<TestCase> test_cases{
      {
          .releaseTimes{9, 29, 49, 50},
          .keysPressed = "cbcd",
          .expected = 'c',
      },
      {
          .releaseTimes{12, 23, 36, 46, 62},
          .keysPressed = "spuda",
          .expected = 'a',
      },
  };

  for (const auto &[releaseTimes, keysPressed, expected] : test_cases) {
    const auto actual = Solution::slowestKey(releaseTimes, keysPressed);
    REQUIRE(expected == actual);
  }
}
