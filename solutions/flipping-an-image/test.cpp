#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<std::vector<int>> image;
    std::vector<std::vector<int>> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .image{{1, 1, 0}, {1, 0, 1}, {0, 0, 0}},
          .expected{{1, 0, 0}, {0, 1, 0}, {1, 1, 1}},
      },
      {
          .image{{1, 1, 0, 0}, {1, 0, 0, 1}, {0, 1, 1, 1}, {1, 0, 1, 0}},
          .expected{{1, 1, 0, 0}, {0, 1, 1, 0}, {0, 0, 0, 1}, {1, 0, 1, 0}},
      },
  };

  for (const auto &[image, expected] : test_cases) {
    const auto actual = Solution::flipAndInvertImage(image);
    REQUIRE(expected == actual);
  }
}
