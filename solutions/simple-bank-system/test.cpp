#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    std::vector<long long> balance{10, 100, 20, 50, 30};
    auto bank = Bank(balance);

    REQUIRE(true == bank.withdraw(3, 10));
    REQUIRE(true == bank.transfer(5, 1, 20));
    REQUIRE(true == bank.deposit(5, 20));
    REQUIRE(false == bank.transfer(3, 4, 15));
    REQUIRE(false == bank.withdraw(10, 50));
  }
}
