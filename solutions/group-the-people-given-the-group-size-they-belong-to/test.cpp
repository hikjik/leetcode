#include <catch.hpp>

#include <solution.hpp>

#include <set>

void CheckSolution(const std::vector<int> &groupSizes) {
  std::set<int> set;
  const auto groups = Solution::groupThePeople(groupSizes);
  for (const auto &group : groups) {
    for (auto i : group) {
      REQUIRE(groupSizes[i] * 1UL == group.size());
      set.insert(i);
    }
  }
  REQUIRE(set.size() == groupSizes.size());
  REQUIRE(*set.begin() == 0);
  REQUIRE(*set.rbegin() + 1UL == groupSizes.size());
}

TEST_CASE("Simple") {
  {
    std::vector<int> groupSizes{3, 3, 3, 3, 3, 1, 3};
    CheckSolution(groupSizes);
  }
  {
    std::vector<int> groupSizes{2, 1, 3, 3, 3, 2};
    CheckSolution(groupSizes);
  }
}
