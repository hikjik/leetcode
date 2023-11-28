#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<std::vector<int>> buildings;
    std::vector<std::vector<int>> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .buildings{
              {2, 9, 10}, {3, 7, 15}, {5, 12, 12}, {15, 20, 10}, {19, 24, 8}},
          .expected{
              {2, 10}, {3, 15}, {7, 12}, {12, 0}, {15, 10}, {20, 8}, {24, 0}},
      },
      {
          .buildings{{0, 2, 3}, {2, 5, 3}},
          .expected{{0, 3}, {5, 0}},
      },
  };

  SECTION("Multiset") {
    for (const auto &[buildings, expected] : test_cases) {
      const auto actual = multiset::Solution::getSkyline(buildings);
      REQUIRE(expected == actual);
    }
  }

  SECTION("Priority Queue") {
    for (const auto &[buildings, expected] : test_cases) {
      const auto actual = pq::Solution::getSkyline(buildings);
      REQUIRE(expected == actual);
    }
  }
}
