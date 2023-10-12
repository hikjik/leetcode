#include <catch.hpp>

#include <solution.hpp>

#include <set>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> groupSizes;
    std::vector<std::vector<int>> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .groupSizes{3, 3, 3, 3, 3, 1, 3},
          .expected{{5}, {0, 1, 2}, {3, 4, 6}},
      },
      {
          .groupSizes{2, 1, 3, 3, 3, 2},
          .expected{{1}, {0, 5}, {2, 3, 4}},
      },
  };

  for (const auto &[groupSizes, expected] : test_cases) {
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
}
