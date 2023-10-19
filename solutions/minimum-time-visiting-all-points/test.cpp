#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<std::vector<int>> points;int expected;
  };

  std::vector<TestCase> test_cases{
      {.points{{1,1},{3,4},{-1,0}},.expected=7,},{.points{{3,2},{-2,2}},.expected=5,},
  };

  for (const auto &[points,expected] : test_cases) {
    const auto actual = Solution::minTimeToVisitAllPoints(points);
    REQUIRE(expected == actual);
  }
}
