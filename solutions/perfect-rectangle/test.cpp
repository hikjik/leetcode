#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<std::vector<int>> rectangles;
    bool expected;
  };

  std::vector<TestCase> test_cases{
      {
          .rectangles{{0, 0, 1, 1}, {0, 0, 2, 1}, {1, 0, 2, 1}, {0, 2, 2, 3}},
          .expected = false,
      },
      {
          .rectangles{{1, 1, 3, 3},
                      {3, 1, 4, 2},
                      {3, 2, 4, 4},
                      {1, 3, 2, 4},
                      {2, 3, 3, 4}},
          .expected = true,
      },
      {
          .rectangles{{1, 1, 2, 3}, {1, 3, 2, 4}, {3, 1, 4, 2}, {3, 2, 4, 4}},
          .expected = false,
      },
      {
          .rectangles{{1, 1, 3, 3}, {3, 1, 4, 2}, {1, 3, 2, 4}, {2, 2, 4, 4}},
          .expected = false,
      },
      {
          .rectangles{{0, 0, 2, 2}, {1, 1, 3, 3}, {2, 0, 3, 1}, {0, 3, 3, 4}},
          .expected = false,
      },

  };

  for (const auto &[rectangles, expected] : test_cases) {
    const auto actual = Solution::isRectangleCover(rectangles);
    REQUIRE(expected == actual);
  }
}
