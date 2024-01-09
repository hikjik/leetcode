#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<std::vector<int>> rooms;
    std::vector<std::vector<int>> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .rooms{{2147483647, -1, 0, 2147483647},
                 {2147483647, 2147483647, 2147483647, -1},
                 {2147483647, -1, 2147483647, -1},
                 {0, -1, 2147483647, 2147483647}},
          .expected =
              {{3, -1, 0, 1}, {2, 2, 1, -1}, {1, -1, 2, -1}, {0, -1, 3, 4}},
      },
      {
          .rooms{{-1}},
          .expected = {{-1}},
      },
  };

  for (auto &[rooms, expected] : test_cases) {
    Solution::wallsAndGates(rooms);
    REQUIRE(expected == rooms);
  }
}
