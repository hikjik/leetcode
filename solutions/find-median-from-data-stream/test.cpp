#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  MedianFinder median_finder;
  median_finder.addNum(1);
  median_finder.addNum(2);
  REQUIRE(1.5 == median_finder.findMedian());
  median_finder.addNum(3);
  REQUIRE(2.0 == median_finder.findMedian());
}
