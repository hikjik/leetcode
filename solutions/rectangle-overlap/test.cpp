#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> rec1;
    std::vector<int> rec2;
    bool expected;
  };

  std::vector<TestCase> test_cases{
      {
          .rec1{0, 0, 2, 2},
          .rec2{1, 1, 3, 3},
          .expected = true,
      },
      {
          .rec1{0, 0, 1, 1},
          .rec2{1, 0, 2, 1},
          .expected = false,
      },
      {
          .rec1{0, 0, 1, 1},
          .rec2{2, 2, 3, 3},
          .expected = false,
      },
  };

  for (const auto &[rec1, rec2, expected] : test_cases) {
    const auto actual = Solution::isRectangleOverlap(rec1, rec2);
    REQUIRE(expected == actual);
  }
}
