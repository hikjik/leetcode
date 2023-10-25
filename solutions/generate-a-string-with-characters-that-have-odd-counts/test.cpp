#include <catch.hpp>

#include <solution.hpp>

#include <ranges>
#include <unordered_map>

TEST_CASE("Simple") {
  for (int n : {4, 2, 7}) {
    std::unordered_map<char, int> counter;
    for (auto c : Solution::generateTheString(n)) {
      ++counter[c];
    }

    const auto all_odds = std::ranges::all_of(
        counter, [](const auto &p) { return p.second & 1; });
    REQUIRE(all_odds);
  }
}
