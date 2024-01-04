#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> v1;
    std::vector<int> v2;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .v1{1, 0, 0, 2, 3},
          .v2{0, 3, 0, 4, 0},
          .expected = 8,
      },
      {
          .v1{0, 1, 0, 0, 0},
          .v2{0, 0, 0, 0, 2},
          .expected = 0,
      },
      {
          .v1{0, 1, 0, 0, 2, 0, 0},
          .v2{1, 0, 0, 0, 3, 0, 4},
          .expected = 6,
      },
  };

  for (const auto &[v1, v2, expected] : test_cases) {
    const auto actual = SparseVector(v1).dotProduct(SparseVector(v2));
    REQUIRE(expected == actual);
  }
}
