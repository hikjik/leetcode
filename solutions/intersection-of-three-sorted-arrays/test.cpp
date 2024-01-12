#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> arr1;
    std::vector<int> arr2;
    std::vector<int> arr3;
    std::vector<int> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .arr1{1, 2, 3, 4, 5},
          .arr2{1, 2, 5, 7, 9},
          .arr3{1, 3, 4, 5, 8},
          .expected{1, 5},
      },
      {
          .arr1{197, 418, 523, 876, 1356},
          .arr2{501, 880, 1593, 1710, 1870},
          .arr3{521, 682, 1337, 1395, 1764},
          .expected{},
      },
  };

  SECTION("Three Pointers") {
    for (const auto &[arr1, arr2, arr3, expected] : test_cases) {
      const auto actual =
          three_pointers::Solution::arraysIntersection(arr1, arr2, arr3);
      REQUIRE(expected == actual);
    }
  }

  SECTION("STL") {
    for (const auto &[arr1, arr2, arr3, expected] : test_cases) {
      const auto actual = stl::Solution::arraysIntersection(arr1, arr2, arr3);
      REQUIRE(expected == actual);
    }
  }
}
