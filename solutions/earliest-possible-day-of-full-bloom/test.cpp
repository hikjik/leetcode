#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    std::vector<int> plantTime{1, 4, 3};
    std::vector<int> growTime{2, 3, 1};
    REQUIRE(9 == Solution::earliestFullBloom(plantTime, growTime));
  }
  {
    std::vector<int> plantTime{1, 2, 3, 2};
    std::vector<int> growTime{2, 1, 2, 1};
    REQUIRE(9 == Solution::earliestFullBloom(plantTime, growTime));
  }
  {
    std::vector<int> plantTime{1};
    std::vector<int> growTime{1};
    REQUIRE(2 == Solution::earliestFullBloom(plantTime, growTime));
  }
}