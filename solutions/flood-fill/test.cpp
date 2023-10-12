#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<std::vector<int>> image;
    int sr;
    int sc;
    int color;
    std::vector<std::vector<int>> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .image{{1, 1, 1}, {1, 1, 0}, {1, 0, 1}},
          .sr = 1,
          .sc = 1,
          .color = 2,
          .expected{{2, 2, 2}, {2, 2, 0}, {2, 0, 1}},
      },
      {
          .image{{0, 0, 0}, {0, 0, 0}},
          .sr = 0,
          .sc = 0,
          .color = 0,
          .expected{{0, 0, 0}, {0, 0, 0}},
      },
  };

  for (const auto &[image, sr, sc, color, expected] : test_cases) {
    const auto actual = Solution::floodFill(image, sr, sc, color);
    REQUIRE(expected == actual);
  }
}
