#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> sensor1;
    std::vector<int> sensor2;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .sensor1{2, 3, 4, 5},
          .sensor2{2, 1, 3, 4},
          .expected = 1,
      },
      {
          .sensor1{2, 3, 4, 5},
          .sensor2{2, 3, 4, 5},
          .expected = -1,
      },
      {
          .sensor1{2, 2, 2, 2, 2},
          .sensor2{2, 2, 2, 2, 5},
          .expected = -1,
      },
      {
          .sensor1{2, 3, 2, 2, 3, 2},
          .sensor2{2, 3, 2, 3, 2, 7},
          .expected = 2,
      },
  };

  for (const auto &[sensor1, sensor2, expected] : test_cases) {
    const auto actual = Solution::badSensor(sensor1, sensor2);
    REQUIRE(expected == actual);
  }
}
