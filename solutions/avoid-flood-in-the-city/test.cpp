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
  {
    std::vector<int> rains{1, 2, 3, 4};
    const auto ans = Solution::avoidFlood(rains);
    REQUIRE(IsNoFlood(rains, ans));
  }
  {
    std::vector<int> rains{1, 2, 0, 0, 2, 1};
    const auto ans = Solution::avoidFlood(rains);
    REQUIRE(IsNoFlood(rains, ans));
  }
  {
    std::vector<int> rains{1, 2, 0, 2, 1};
    std::vector<int> expected;
    REQUIRE(expected == Solution::avoidFlood(rains));
  }
}
