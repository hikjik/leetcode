#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    std::vector<int> difficulty{2, 4, 6, 8, 10};
    std::vector<int> profit{10, 20, 30, 40, 50};
    std::vector<int> workers{4, 5, 6, 7};
    REQUIRE(100 == Solution::maxProfitAssignment(difficulty, profit, workers));
  }
  {
    std::vector<int> difficulty{85, 47, 57};
    std::vector<int> profit{24, 66, 99};
    std::vector<int> workers{40, 25, 25};
    REQUIRE(0 == Solution::maxProfitAssignment(difficulty, profit, workers));
  }
}
