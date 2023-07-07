#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  REQUIRE(4 == Solution::maxConsecutiveAnswers("TTFF", 2));
  REQUIRE(3 == Solution::maxConsecutiveAnswers("TFFT", 1));
  REQUIRE(5 == Solution::maxConsecutiveAnswers("TTFTTFTT", 1));
}
