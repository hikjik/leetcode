#include <catch.hpp>

#include <solution.hpp>

#include <unordered_map>
#include <vector>

TEST_CASE("Simple") {
  std::vector<int> values{1, 2, 3};
  auto head = VectorToList(values);

  auto obj = new Solution(head);

  std::unordered_map<int, int> cnt;
  int N = 10000;
  for (int i = 0; i < N; i++) {
    cnt[obj->getRandom()]++;
  }

  REQUIRE(3 == cnt.size());
  for (auto value : values) {
    REQUIRE_THAT(cnt[value] * 1.0 / N,
                 Catch::Matchers::WithinAbs(1.0 / 3, 1e-2));
  }

  FreeList(head);
}
