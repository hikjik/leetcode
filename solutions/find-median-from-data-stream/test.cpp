#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  auto median_finder = MedianFinder();

  median_finder.addNum(1);
  median_finder.addNum(2);
  REQUIRE(1.5 == Approx(median_finder.findMedian()));
  median_finder.addNum(3);
  REQUIRE(2.0 == Approx(median_finder.findMedian()));
}
