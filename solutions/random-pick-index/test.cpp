#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  std::vector<int> nums{1, 2, 3, 3, 3};
  auto solution = Solution(nums);

  REQUIRE(0 == solution.pick(1));
  REQUIRE(1 == solution.pick(2));

  std::unordered_map<int, int> counter;
  int N = 100000;
  for (int i = 0; i < N; ++i) {
    ++counter[solution.pick(3)];
  }

  REQUIRE(3 == counter.size());
  for (const auto &[index, freq] : counter) {
    REQUIRE(2 <= index);
    REQUIRE(index <= 4);
    REQUIRE_THAT(freq * 1.0 / N, Catch::Matchers::WithinAbs(1.0 / 3, 1e-2));
  }
}
