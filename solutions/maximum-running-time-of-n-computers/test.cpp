#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    int n;
    std::vector<int> batteries;
    long long expected;
  };

  std::vector<TestCase> test_cases{
      {
          .n = 2,
          .batteries{3, 3, 3},
          .expected = 4,
      },
      {
          .n = 2,
          .batteries{1, 1, 1, 1},
          .expected = 2,
      },
  };

  for (const auto &[n, batteries, expected] : test_cases) {
    const auto actual = Solution::maxRunTime(n, batteries);
    REQUIRE(expected == actual);
  }
}
