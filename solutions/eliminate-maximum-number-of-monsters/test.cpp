#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> dist;
    std::vector<int> speed;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .dist{1, 3, 4},
          .speed{1, 1, 1},
          .expected = 3,
      },
      {
          .dist{1, 1, 2, 3},
          .speed{1, 1, 1, 1},
          .expected = 1,
      },
      {
          .dist{3, 2, 4},
          .speed{5, 3, 2},
          .expected = 1,
      },
  };

  SECTION("Sorting") {
    for (const auto &[dist, speed, expected] : test_cases) {
      const auto actual = sorting::Solution::eliminateMaximum(dist, speed);
      REQUIRE(expected == actual);
    }
  }

  SECTION("Counting") {
    for (const auto &[dist, speed, expected] : test_cases) {
      const auto actual = counting::Solution::eliminateMaximum(dist, speed);
      REQUIRE(expected == actual);
    }
  }
}
