#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    int numCourses;
    std::vector<std::vector<int>> prerequisites;
    std::vector<int> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .numCourses = 2,
          .prerequisites{{1, 0}},
          .expected{0, 1},
      },
      {
          .numCourses = 4,
          .prerequisites{{1, 0}, {2, 0}, {3, 1}, {3, 2}},
          .expected{0, 2, 1, 3},
      },
      {
          .numCourses = 1,
          .prerequisites{},
          .expected{0},
      },

      {
          .numCourses = 2,
          .prerequisites{{0, 1}, {1, 0}},
          .expected{},
      },
      {
          .numCourses = 3,
          .prerequisites{{1, 0}, {1, 2}, {0, 1}},
          .expected{},
      },
  };

  for (const auto &[numCourses, prerequisites, expected] : test_cases) {
    const auto actual = Solution::findOrder(numCourses, prerequisites);
    if (expected.empty()) {
      REQUIRE(actual.empty());
    } else {
      REQUIRE(numCourses * 1UL == actual.size());

      std::unordered_map<int, int> positions;
      for (size_t i = 0; i < actual.size(); ++i) {
        positions[actual[i]] = i;
      }
      REQUIRE(numCourses * 1UL == positions.size());
      for (const auto &edge : prerequisites) {
        REQUIRE(positions[edge[0]] > positions[edge[1]]);
      }
    }
  }
}
