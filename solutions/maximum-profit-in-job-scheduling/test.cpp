#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    std::vector<int> startTime{1, 2, 3, 3};
    std::vector<int> endTime{3, 4, 5, 6};
    std::vector<int> profit{50, 10, 40, 70};
    REQUIRE(120 == Solution::jobScheduling(startTime, endTime, profit));
  }
  {
    std::vector<int> startTime{1, 2, 3, 4, 6};
    std::vector<int> endTime{3, 5, 10, 6, 9};
    std::vector<int> profit{20, 20, 100, 70, 60};
    REQUIRE(150 == Solution::jobScheduling(startTime, endTime, profit));
  }
  {
    std::vector<int> startTime{1, 1, 1};
    std::vector<int> endTime{2, 3, 4};
    std::vector<int> profit{5, 6, 4};
    REQUIRE(6 == Solution::jobScheduling(startTime, endTime, profit));
  }
}
