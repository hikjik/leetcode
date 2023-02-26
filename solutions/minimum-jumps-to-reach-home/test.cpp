#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  //   {
  //     std::vector<int> forbidden{14, 4, 18, 1, 15};
  //     int a = 3, b = 15, x = 9;
  //     REQUIRE(3 == Solution::minimumJumps(forbidden, a, b, x));
  //   }
  {
    std::vector<int> forbidden{8, 3, 16, 6, 12, 20};
    int a = 15, b = 13, x = 11;
    REQUIRE(-1 == Solution::minimumJumps(forbidden, a, b, x));
  }
  {
    std::vector<int> forbidden{1, 6, 2, 14, 5, 17, 4};
    int a = 16, b = 9, x = 7;
    REQUIRE(2 == Solution::minimumJumps(forbidden, a, b, x));
  }
  {
    std::vector<int> forbidden{
        162, 118, 178, 152, 167, 100, 40,  74,  199, 186, 26, 73,  200, 127,
        30,  124, 193, 84,  184, 36,  103, 149, 153, 9,   54, 154, 133, 95,
        45,  198, 79,  157, 64,  122, 59,  71,  48,  177, 82, 35,  14,  176,
        16,  108, 111, 6,   168, 31,  134, 164, 136, 72,  98};
    int a = 29, b = 98, x = 80;
    REQUIRE(121 == Solution::minimumJumps(forbidden, a, b, x));
  }
}
