#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<std::vector<int>> image;
    int threshold;
    std::vector<std::vector<int>> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .image{{1, 1, 4, 1}, {10, 8, 13, 17}, {2, 12, 1, 16}},
          .threshold = 14,
          .expected{{5, 5, 5, 1}, {5, 5, 5, 17}, {5, 5, 5, 16}},
      },
      {
          .image{{5, 6, 7, 10}, {8, 9, 10, 10}, {11, 12, 13, 10}},
          .threshold = 3,
          .expected{{9, 9, 9, 9}, {9, 9, 9, 9}, {9, 9, 9, 9}},
      },
      {
          .image{{10, 20, 30}, {15, 25, 35}, {20, 30, 40}, {25, 35, 45}},
          .threshold = 12,
          .expected{{25, 25, 25}, {27, 27, 27}, {27, 27, 27}, {30, 30, 30}},
      },
      {
          .image{{5, 6, 7}, {8, 9, 10}, {11, 12, 13}},
          .threshold = 1,
          .expected{{5, 6, 7}, {8, 9, 10}, {11, 12, 13}},
      },
  };

  for (const auto &[image, threshold, expected] : test_cases) {
    const auto actual = Solution::resultGrid(image, threshold);
    REQUIRE(expected == actual);
  }
}
