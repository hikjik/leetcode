#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Brute Force") {
  {
    std::vector<std::vector<int>> rectangle{
        {1, 2, 1}, {4, 3, 4}, {3, 2, 1}, {1, 1, 1}};
    brute_force::SubrectangleQueries queries(rectangle);

    REQUIRE(1 == queries.getValue(0, 2));
    queries.updateSubrectangle(0, 0, 3, 2, 5);
    REQUIRE(5 == queries.getValue(0, 2));
    REQUIRE(5 == queries.getValue(3, 1));
    queries.updateSubrectangle(3, 0, 3, 2, 10);
    REQUIRE(10 == queries.getValue(3, 1));
    REQUIRE(5 == queries.getValue(0, 2));
  }
  {
    std::vector<std::vector<int>> rectangle{{1, 1, 1}, {2, 2, 2}, {3, 3, 3}};
    brute_force::SubrectangleQueries queries(rectangle);

    REQUIRE(1 == queries.getValue(0, 0));
    queries.updateSubrectangle(0, 0, 2, 2, 100);
    REQUIRE(100 == queries.getValue(0, 0));
    REQUIRE(100 == queries.getValue(2, 2));
    queries.updateSubrectangle(1, 1, 2, 2, 20);
    REQUIRE(20 == queries.getValue(2, 2));
  }
}

TEST_CASE("Optimize") {
  {
    std::vector<std::vector<int>> rectangle{
        {1, 2, 1}, {4, 3, 4}, {3, 2, 1}, {1, 1, 1}};
    optimized::SubrectangleQueries queries(rectangle);

    REQUIRE(1 == queries.getValue(0, 2));
    queries.updateSubrectangle(0, 0, 3, 2, 5);
    REQUIRE(5 == queries.getValue(0, 2));
    REQUIRE(5 == queries.getValue(3, 1));
    queries.updateSubrectangle(3, 0, 3, 2, 10);
    REQUIRE(10 == queries.getValue(3, 1));
    REQUIRE(5 == queries.getValue(0, 2));
  }
  {
    std::vector<std::vector<int>> rectangle{{1, 1, 1}, {2, 2, 2}, {3, 3, 3}};
    optimized::SubrectangleQueries queries(rectangle);

    REQUIRE(1 == queries.getValue(0, 0));
    queries.updateSubrectangle(0, 0, 2, 2, 100);
    REQUIRE(100 == queries.getValue(0, 0));
    REQUIRE(100 == queries.getValue(2, 2));
    queries.updateSubrectangle(1, 1, 2, 2, 20);
    REQUIRE(20 == queries.getValue(2, 2));
  }
}
