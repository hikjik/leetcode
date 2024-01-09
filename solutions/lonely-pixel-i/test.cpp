#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<std::vector<char>> picture;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .picture{{'W', 'W', 'B'}, {'W', 'B', 'W'}, {'B', 'W', 'W'}},
          .expected = 3,
      },
      {
          .picture{{'B', 'B', 'B'}, {'B', 'B', 'W'}, {'B', 'B', 'B'}},
          .expected = 0,
      },
  };

  for (const auto &[picture, expected] : test_cases) {
    const auto actual = Solution::findLonelyPixel(picture);
    REQUIRE(expected == actual);
  }
}
