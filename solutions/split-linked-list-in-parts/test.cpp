#include <catch.hpp>

#include <solution.hpp>

void CheckSolution(size_t k, const std::vector<int> &values,
                   const std::vector<std::vector<int>> &expected) {
  auto head = VectorToList(values);
  auto parts = Solution().splitListToParts(head, k);
  REQUIRE(k == parts.size());

  std::vector<std::vector<int>> actual;
  for (auto *part : parts) {
    actual.push_back(ListToVector(part));
  }
  REQUIRE(actual == expected);

  for (auto *part : parts) {
    FreeList(part);
  }
}

TEST_CASE("Simple") {
  {
    int k = 5;
    std::vector<int> values{1, 2, 3};
    std::vector<std::vector<int>> expected{{1}, {2}, {3}, {}, {}};
    CheckSolution(k, values, expected);
  }
  {
    int k = 3;
    std::vector<int> values{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::vector<std::vector<int>> expected{{1, 2, 3, 4}, {5, 6, 7}, {8, 9, 10}};
    CheckSolution(k, values, expected);
  }
  {
    int k = 2;
    std::vector<int> values;
    std::vector<std::vector<int>> expected{{}, {}};
    CheckSolution(k, values, expected);
  }
}
