#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    std::vector<std::vector<std::string>> equations{{"a", "b"}, {"b", "c"}};
    std::vector<double> values{2.0, 3.0};
    std::vector<std::vector<std::string>> queries{
        {"a", "c"}, {"b", "a"}, {"a", "e"}, {"a", "a"}, {"x", "x"}};
    std::vector<double> expected{6.00000, 0.50000, -1.00000, 1.00000, -1.00000};
    REQUIRE(expected == Solution::calcEquation(equations, values, queries));
  }
  {
    std::vector<std::vector<std::string>> equations{
        {"a", "b"}, {"b", "c"}, {"bc", "cd"}};
    std::vector<double> values{1.5, 2.5, 5.0};
    std::vector<std::vector<std::string>> queries{
        {"a", "c"}, {"c", "b"}, {"bc", "cd"}, {"cd", "bc"}};
    std::vector<double> expected{3.75000, 0.40000, 5.00000, 0.20000};
    REQUIRE(expected == Solution::calcEquation(equations, values, queries));
  }
  {
    std::vector<std::vector<std::string>> equations{{"a", "b"}};
    std::vector<double> values{0.5};
    std::vector<std::vector<std::string>> queries{
        {"a", "b"}, {"b", "a"}, {"a", "c"}, {"x", "y"}};
    std::vector<double> expected{0.50000, 2.00000, -1.00000, -1.00000};
    REQUIRE(expected == Solution::calcEquation(equations, values, queries));
  }
}
