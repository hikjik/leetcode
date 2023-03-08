#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    std::vector<std::string> words{"2", "1", "+", "3", "*"};
    REQUIRE(9 == Solution::evalRPN(words));
  }
  {
    std::vector<std::string> words{"4", "13", "5", "/", "+"};
    REQUIRE(6 == Solution::evalRPN(words));
  }
  {
    std::vector<std::string> words{"10", "6", "9",  "3", "+", "-11", "*",
                                   "/",  "*", "17", "+", "5", "+"};
    REQUIRE(22 == Solution::evalRPN(words));
  }
}
