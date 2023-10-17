#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string s;
    std::vector<int> distance;
    bool expected;
  };

  std::vector<TestCase> test_cases{
      {
          .s = "abaccb",
          .distance{1, 3, 0, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
          .expected = true,
      },
      {
          .s = "aa",
          .distance{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
          .expected = false,
      },
  };

  for (const auto &[s, distance, expected] : test_cases) {
    const auto actual = Solution::checkDistances(s, distance);
    REQUIRE(expected == actual);
  }
}
