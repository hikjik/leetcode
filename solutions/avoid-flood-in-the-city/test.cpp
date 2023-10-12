#include <catch.hpp>

#include <solution.hpp>

#include <unordered_set>

bool IsNoFlood(const std::vector<int> &rains, const std::vector<int> &ans) {
  std::unordered_set<int> set;
  for (size_t i = 0; i < rains.size(); ++i) {
    if (rains[i] != 0) {
      if (ans[i] != -1 || set.count(rains[i])) {
        return false;
      }
      set.insert(rains[i]);
    } else {
      if (ans[i] < 1) {
        return false;
      }
      set.erase(ans[i]);
    }
  }
  return true;
}

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> rains;
    std::vector<int> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .rains{1, 2, 3, 4},
          .expected{-1, -1, -1, -1},
      },
      {
          .rains{1, 2, 0, 0, 2, 1},
          .expected{-1, -1, 2, 1, -1, -1},
      },
      {
          .rains{1, 2, 0, 1, 2},
          .expected{},
      },
  };

  for (const auto &[rains, expected] : test_cases) {
    const auto actual = Solution::avoidFlood(rains);
    if (expected.empty()) {
      REQUIRE(expected == actual);
    } else {
      REQUIRE(IsNoFlood(rains, actual));
    }
  }
}
