#include <catch.hpp>

#include <solution.hpp>

void CheckSolution(std::string s, bool is_possible) {
  auto ans = Solution::reorganizeString(s);
  if (is_possible) {
    for (size_t i = 0; i + 1 < ans.size(); ++i) {
      REQUIRE(ans[i] != ans[i + 1]);
    }

    std::sort(ans.begin(), ans.end());
    std::sort(s.begin(), s.end());
    REQUIRE(s == ans);
  } else {
    REQUIRE(ans == "");
  }
}

TEST_CASE("Simple") {
  CheckSolution("aab", true);
  CheckSolution("aaab", false);
}
