#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    int n;
    std::vector<std::vector<int>> requests;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .n = 5,
          .requests{{0, 1}, {1, 0}, {0, 1}, {1, 2}, {2, 0}, {3, 4}},
          .expected = 5,
      },
      {
          .n = 3,
          .requests{{0, 0}, {1, 2}, {2, 1}},
          .expected = 3,
      },
      {
          .n = 4,
          .requests{{0, 3}, {3, 1}, {1, 2}, {2, 0}},
          .expected = 4,
      },
  };

  for (const auto &[n, requests, expected] : test_cases) {
    const auto actual = Solution::maximumRequests(n, requests);
    REQUIRE(expected == actual);
  }
}
