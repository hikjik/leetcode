#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<std::vector<int>> rooms;
    bool expected;
  };

  std::vector<TestCase> test_cases{
      {
          .rooms{{1}, {2}, {3}, {}},
          .expected = true,
      },
      {
          .rooms{{1, 3}, {3, 0, 1}, {2}, {0}},
          .expected = false,
      },
  };

  for (const auto &[rooms, expected] : test_cases) {
    const auto actual = Solution::canVisitAllRooms(rooms);
    REQUIRE(expected == actual);
  }
}
