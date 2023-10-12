#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> asteroids;
    std::vector<int> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .asteroids{5, 10, -5},
          .expected{5, 10},
      },
      {
          .asteroids{8, -8},
          .expected{},
      },
      {
          .asteroids{10, 2, -5},
          .expected{10},
      },
  };

  for (const auto &[asteroids, expected] : test_cases) {
    const auto actual = Solution::asteroidCollision(asteroids);
    REQUIRE(expected == actual);
  }
}
