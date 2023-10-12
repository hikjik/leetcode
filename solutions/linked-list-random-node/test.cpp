#include <catch.hpp>

#include <solution.hpp>

#include <unordered_map>
#include <vector>

TEST_CASE("Simple") {
  List head{1, 2, 3};
  auto solution = Solution(head);

  std::unordered_map<int, int> counter;
  int N = 10000;
  for (int i = 0; i < N; i++) {
    ++counter[solution.getRandom()];
  }

  REQUIRE(3 == counter.size());
  for (const auto &[value, freq] : counter) {
    REQUIRE(1 <= value);
    REQUIRE(value <= 3);
    REQUIRE_THAT(freq * 1.0 / N, Catch::Matchers::WithinAbs(1.0 / 3, 1e-2));
  }
}
