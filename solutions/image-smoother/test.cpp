#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<std::vector<int>> img;
    std::vector<std::vector<int>> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .img{{1, 1, 1}, {1, 0, 1}, {1, 1, 1}},
          .expected{{0, 0, 0}, {0, 0, 0}, {0, 0, 0}},
      },
      {
          .img{{100, 200, 100}, {200, 50, 200}, {100, 200, 100}},
          .expected{{137, 141, 137}, {141, 138, 141}, {137, 141, 137}},
      },
  };

  for (const auto &[img, expected] : test_cases) {
    const auto actual = Solution::imageSmoother(img);
    REQUIRE(expected == actual);
  }
}
