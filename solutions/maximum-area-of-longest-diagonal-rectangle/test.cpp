#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<std::vector<int>> dimensions;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .dimensions{{9, 3}, {8, 6}},
          .expected = 48,
      },
      {
          .dimensions{{3, 4}, {4, 3}},
          .expected = 12,
      },
  };

  for (const auto &[dimensions, expected] : test_cases) {
    const auto actual = Solution::areaOfMaxDiagonal(dimensions);
    REQUIRE(expected == actual);
  }
}
