#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> locations;
    int start;
    int finish;
    int fuel;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .locations{2, 3, 6, 8, 4},
          .start = 1,
          .finish = 3,
          .fuel = 5,
          .expected = 4,
      },
      {
          .locations{4, 3, 1},
          .start = 1,
          .finish = 0,
          .fuel = 6,
          .expected = 5,
      },
      {
          .locations{5, 2, 1},
          .start = 0,
          .finish = 2,
          .fuel = 3,
          .expected = 0,
      },
  };

  for (const auto &[locations, start, finish, fuel, expected] : test_cases) {
    const auto actual = Solution::countRoutes(locations, start, finish, fuel);
    REQUIRE(expected == actual);
  }
}
