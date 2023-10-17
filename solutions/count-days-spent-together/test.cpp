#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string arriveAlice;
    std::string leaveAlice;
    std::string arriveBob;
    std::string leaveBob;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .arriveAlice = "08-15",
          .leaveAlice = "08-18",
          .arriveBob = "08-16",
          .leaveBob = "08-19",
          .expected = 3,
      },
      {
          .arriveAlice = "10-01",
          .leaveAlice = "10-31",
          .arriveBob = "11-01",
          .leaveBob = "12-31",
          .expected = 0,
      },
  };

  for (const auto &[arriveAlice, leaveAlice, arriveBob, leaveBob, expected] :
       test_cases) {
    const auto actual = Solution::countDaysTogether(arriveAlice, leaveAlice,
                                                    arriveBob, leaveBob);
    REQUIRE(expected == actual);
  }
}
