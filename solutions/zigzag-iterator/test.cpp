#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> v1;
    std::vector<int> v2;
    std::vector<int> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .v1{1, 2},
          .v2{3, 4, 5, 6},
          .expected{1, 3, 2, 4, 5, 6},
      },
      {
          .v1{1},
          .v2{},
          .expected{1},
      },
      {
          .v1{},
          .v2{1},
          .expected{1},
      },
  };

  SECTION("List") {
    for (const auto &[v1, v2, expected] : test_cases) {
      lst::ZigzagIterator iterator(v1, v2);
      std::vector<int> actual;
      while (iterator.hasNext()) {
        actual.push_back(iterator.next());
      }
      REQUIRE(expected == actual);
    }
  }

  SECTION("Queue") {
    for (const auto &[v1, v2, expected] : test_cases) {
      queue::ZigzagIterator iterator(v1, v2);
      std::vector<int> actual;
      while (iterator.hasNext()) {
        actual.push_back(iterator.next());
      }
      REQUIRE(expected == actual);
    }
  }
}
