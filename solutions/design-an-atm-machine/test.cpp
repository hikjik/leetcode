#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {

    auto a_t_m = ATM();

    a_t_m.deposit({0, 0, 1, 2, 1});
    REQUIRE(std::vector<int>{0, 0, 1, 0, 1} == a_t_m.withdraw(600));
    a_t_m.deposit({0, 1, 0, 1, 1});
    REQUIRE(std::vector<int>{-1} == a_t_m.withdraw(600));
    REQUIRE(std::vector<int>{0, 1, 0, 0, 1} == a_t_m.withdraw(550));
  }
}
