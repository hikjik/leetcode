#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    int mainTank;
    int additionalTank;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .mainTank = 5,
          .additionalTank = 10,
          .expected = 60,
      },
      {
          .mainTank = 1,
          .additionalTank = 2,
          .expected = 10,
      },
      {
          .mainTank = 25,
          .additionalTank = 6,
          .expected = 310,
      },
      {
          .mainTank = 9,
          .additionalTank = 2,
          .expected = 110,
      },
  };

  for (const auto &[mainTank, additionalTank, expected] : test_cases) {
    const auto actual = Solution::distanceTraveled(mainTank, additionalTank);
    REQUIRE(expected == actual);
  }
}
