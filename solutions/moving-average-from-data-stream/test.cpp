#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    int size = 3;
    auto moving_average = MovingAverage(size);

    REQUIRE(1.0 == Approx(moving_average.next(1)));
    REQUIRE(5.5 == Approx(moving_average.next(10)));
    REQUIRE(4.66667 == Approx(moving_average.next(3)));
    REQUIRE(6.0 == Approx(moving_average.next(5)));
  }
}
