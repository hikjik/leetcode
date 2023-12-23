#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    int n;
    std::vector<std::vector<int>> restrictions;
    std::vector<std::vector<int>> requests;
    std::vector<bool> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .n = 3,
          .restrictions{{0, 1}},
          .requests{{0, 2}, {2, 1}},
          .expected{true, false},
      },
      {
          .n = 3,
          .restrictions{{0, 1}},
          .requests{{1, 2}, {0, 2}},
          .expected{true, false},
      },
      {
          .n = 5,
          .restrictions{{0, 1}, {1, 2}, {2, 3}},
          .requests{{0, 4}, {1, 2}, {3, 1}, {3, 4}},
          .expected{true, false, true, false},
      },
  };

  for (const auto &[n, restrictions, requests, expected] : test_cases) {
    const auto actual = Solution::friendRequests(n, restrictions, requests);
    REQUIRE(expected == actual);
  }
}
