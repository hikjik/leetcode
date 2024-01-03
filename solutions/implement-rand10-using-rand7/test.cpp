#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  Solution solution;
  std::unordered_map<int, int> cnt;
  const int N = 100'000;
  for (int i = 0; i < N; ++i) {
    ++cnt[solution.rand10()];
  }

  REQUIRE(10 == cnt.size());
  for (const auto &[index, freq] : cnt) {
    REQUIRE(1 <= index);
    REQUIRE(index <= 10);
    REQUIRE_THAT(freq * 1.0 / N, Catch::Matchers::WithinAbs(1.0 / 10, 1e-2));
  }
}
