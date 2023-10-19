#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    int rows;
    int cols;
    int rCenter;
    int cCenter;
  };

  std::vector<TestCase> test_cases{
      {
          .rows = 1,
          .cols = 2,
          .rCenter = 0,
          .cCenter = 0,
      },
      {
          .rows = 2,
          .cols = 2,
          .rCenter = 0,
          .cCenter = 1,
      },
      {
          .rows = 2,
          .cols = 3,
          .rCenter = 1,
          .cCenter = 2,
      },
  };

  for (const auto &[rows, cols, rCenter, cCenter] : test_cases) {
    const auto cells =
        Solution::allCellsDistOrder(rows, cols, rCenter, cCenter);

    REQUIRE(std::ssize(cells) == rows * cols);

    auto dist = [rCenter, cCenter](const std::vector<int> &cell) {
      return std::abs(cell[0] - rCenter) + std::abs(cell[1] - cCenter);
    };

    REQUIRE(std::is_sorted(cells.begin(), cells.end(),
                           [&](const auto &lhs, const auto &rhs) {
                             return dist(lhs) < dist(rhs);
                           }));
  }
}
