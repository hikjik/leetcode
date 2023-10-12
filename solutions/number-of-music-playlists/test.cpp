#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    int n;
    int goal;
    int k;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .n = 3,
          .goal = 3,
          .k = 1,
          .expected = 6,
      },
      {
          .n = 2,
          .goal = 3,
          .k = 0,
          .expected = 6,
      },
      {
          .n = 2,
          .goal = 3,
          .k = 1,
          .expected = 2,
      },
  };

  for (const auto &[n, goal, k, expected] : test_cases) {
    const auto actual = Solution::numMusicPlaylists(n, goal, k);
    REQUIRE(expected == actual);
  }
}
