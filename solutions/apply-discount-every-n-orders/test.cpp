#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  int n = 3;
  int discount = 50;
  std::vector<int> products{1, 2, 3, 4, 5, 6, 7};
  std::vector<int> prices{100, 200, 300, 400, 300, 200, 100};
  auto cashier = Cashier(n, discount, products, prices);

  REQUIRE(500.0 == Approx(cashier.getBill({1, 2}, {1, 2})));
  REQUIRE(4000.0 == Approx(cashier.getBill({3, 7}, {10, 10})));
  REQUIRE(800.0 == Approx(cashier.getBill({1, 2, 3, 4, 5, 6, 7},
                                          {1, 1, 1, 1, 1, 1, 1})));
  REQUIRE(4000.0 == Approx(cashier.getBill({4}, {10})));
  REQUIRE(4000.0 == Approx(cashier.getBill({7, 3}, {10, 10})));
  REQUIRE(7350.0 == Approx(cashier.getBill({7, 5, 3, 1, 6, 4, 2},
                                           {10, 10, 10, 9, 9, 9, 7})));
  REQUIRE(2500.0 == Approx(cashier.getBill({2, 3, 5}, {5, 3, 2})));
}
