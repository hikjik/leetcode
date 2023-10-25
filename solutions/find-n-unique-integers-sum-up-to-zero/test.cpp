#include <catch.hpp>

#include <solution.hpp>

#include <numeric>
#include <set>

TEST_CASE("Simple") {
  for (int n : {1, 3, 5}) {
    const auto actual = Solution::sumZero(n);
    REQUIRE(n == std::ssize(std::set<int>(actual.begin(), actual.end())));
    REQUIRE(0 == std::accumulate(actual.begin(), actual.end(), 0));
  }
}
