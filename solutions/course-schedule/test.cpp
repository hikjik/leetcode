#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    int numCourses;
    std::vector<std::vector<int>> prerequisites;
    bool expected;
  };

  std::vector<TestCase> test_cases{
      {
          .numCourses = 2,
          .prerequisites{{1, 0}},
          .expected = true,
      },
      {
          .numCourses = 2,
          .prerequisites{{1, 0}, {0, 1}},
          .expected = false,
      },
  };

  for (const auto &[numCourses, prerequisites, expected] : test_cases) {
    const auto actual = Solution::canFinish(numCourses, prerequisites);
    REQUIRE(expected == actual);
  }
}
