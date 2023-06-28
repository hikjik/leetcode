#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    std::vector<int> rods{1, 2, 3, 6};
    REQUIRE(6 == Solution::tallestBillboard(rods));
  }
  {
    std::vector<int> rods{1, 2, 3, 4, 5, 6};
    REQUIRE(10 == Solution::tallestBillboard(rods));
  }
  {
    std::vector<int> rods{1, 2};
    REQUIRE(0 == Solution::tallestBillboard(rods));
  }
}