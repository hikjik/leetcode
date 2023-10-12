#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> rods;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .rods{1, 2, 3, 6},
          .expected = 6,
      },
      {
          .rods{1, 2, 3, 4, 5, 6},
          .expected = 10,
      },
      {
          .rods{1, 2},
          .expected = 0,
      },
  };

  for (const auto &[rods, expected] : test_cases) {
    const auto actual = Solution::tallestBillboard(rods);
    REQUIRE(expected == actual);
  }
}
