#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    std::string word("998244353");
    std::vector<int> nums{1, 1, 0, 0, 0, 1, 1, 0, 0};
    REQUIRE(nums == Solution::divisibilityArray(word, 3));
  }
  {
    std::string word("1010");
    std::vector<int> nums{0, 1, 0, 1};
    REQUIRE(nums == Solution::divisibilityArray(word, 10));
  }
}
