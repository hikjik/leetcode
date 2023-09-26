#include <catch.hpp>

#include <solution.hpp>

#include <algorithm>
#include <numeric>

TEST_CASE("No solution") {
  int n = 8, m = 2;
  std::vector<int> group{-1, -1, 1, 0, 0, 1, 0, -1};
  std::vector<std::vector<int>> beforeItems{{},  {6}, {5}, {6},
                                            {3}, {},  {4}, {}};
  std::vector<int> expected;
  REQUIRE(expected == Solution::sortItems(n, m, group, beforeItems));
}

TEST_CASE("Answer contain all items") {
  int n = 8, m = 2;
  std::vector<int> group{-1, -1, 1, 0, 0, 1, 0, -1};
  std::vector<std::vector<int>> beforeItems{{},     {6}, {5}, {6},
                                            {3, 6}, {},  {},  {}};
  const auto sorted_items = Solution::sortItems(n, m, group, beforeItems);

  std::vector<int> items(n);
  std::iota(items.begin(), items.end(), 0);

  REQUIRE(items.size() == sorted_items.size());
  REQUIRE(
      std::is_permutation(items.begin(), items.end(), sorted_items.begin()));
}

TEST_CASE("Check beforeItems relations") {
  int n = 8, m = 2;
  std::vector<int> group{-1, -1, 1, 0, 0, 1, 0, -1};
  std::vector<std::vector<int>> beforeItems{{},     {6}, {5}, {6},
                                            {3, 6}, {},  {},  {}};
  const auto items = Solution::sortItems(n, m, group, beforeItems);

  std::vector<int> positions(n);
  for (int i = 0; i < n; ++i) {
    positions[items[i]] = i;
  }

  for (int i = 0; i < n; ++i) {
    for (int j : beforeItems[i]) {
      REQUIRE(positions[j] < positions[i]);
    }
  }
}

TEST_CASE("Items in group are next to each other") {
  int n = 8, m = 2;
  std::vector<int> group{-1, -1, 1, 0, 0, 1, 0, -1};
  std::vector<std::vector<int>> beforeItems{{},     {6}, {5}, {6},
                                            {3, 6}, {},  {},  {}};
  const auto items = Solution::sortItems(n, m, group, beforeItems);

  std::vector<std::vector<size_t>> positions(m);
  for (size_t i = 0; i < items.size(); ++i) {
    const auto item = items[i];
    if (group[item] != -1) {
      positions[group[item]].push_back(i);
    }
  }

  for (auto g : positions) {
    auto [it_min, it_max] = std::minmax_element(g.begin(), g.end());
    REQUIRE(g.size() == *it_max - *it_min + 1);
  }
}
