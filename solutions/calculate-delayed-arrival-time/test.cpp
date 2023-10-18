#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    int arrivalTime;
    int delayedTime;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .arrivalTime = 15,
          .delayedTime = 5,
          .expected = 20,
      },
      {
          .arrivalTime = 13,
          .delayedTime = 11,
          .expected = 0,
      },
  };

  for (const auto &[arrivalTime, delayedTime, expected] : test_cases) {
    const auto actual =
        Solution::findDelayedArrivalTime(arrivalTime, delayedTime);
    REQUIRE(expected == actual);
  }
}
