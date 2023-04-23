#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    int n = 3;
    std::vector<std::string> expected{"1", "2", "Fizz"};
    REQUIRE(expected == Solution::fizzBuzz(n));
  }
  {
    int n = 5;
    std::vector<std::string> expected{"1", "2", "Fizz", "4", "Buzz"};
    REQUIRE(expected == Solution::fizzBuzz(n));
  }
  {
    int n = 15;
    std::vector<std::string> expected{
        "1",    "2",    "Fizz", "4",    "Buzz", "Fizz", "7",       "8",
        "Fizz", "Buzz", "11",   "Fizz", "13",   "14",   "FizzBuzz"};
    REQUIRE(expected == Solution::fizzBuzz(n));
  }
}
