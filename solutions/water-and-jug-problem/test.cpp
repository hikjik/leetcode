#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    int jug1Capacity;
    int jug2Capacity;
    int targetCapacity;
    bool expected;
  };

  std::vector<TestCase> test_cases{
      {
          .jug1Capacity = 3,
          .jug2Capacity = 5,
          .targetCapacity = 4,
          .expected = true,
      },
      {
          .jug1Capacity = 2,
          .jug2Capacity = 6,
          .targetCapacity = 5,
          .expected = false,
      },
      {
          .jug1Capacity = 1,
          .jug2Capacity = 2,
          .targetCapacity = 3,
          .expected = true,
      },
  };

  for (const auto &[jug1Capacity, jug2Capacity, targetCapacity, expected] :
       test_cases) {
    const auto actual =
        Solution::canMeasureWater(jug1Capacity, jug2Capacity, targetCapacity);
    REQUIRE(expected == actual);
  }
}
