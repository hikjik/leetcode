#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> obstacles;
    std::vector<int> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .obstacles{1, 2, 3, 2},
          .expected{1, 2, 3, 3},
      },
      {
          .obstacles{2, 2, 1},
          .expected{1, 2, 1},
      },
      {
          .obstacles{3, 1, 5, 6, 4, 2},
          .expected{1, 1, 2, 3, 2, 2},
      },
  };

  for (const auto &[obstacles, expected] : test_cases) {
    const auto actual =
        Solution::longestObstacleCourseAtEachPosition(obstacles);
    REQUIRE(expected == actual);
  }
}
