#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    std::vector<std::string> names{"one", "two", "three"};
    std::vector<int> columns{2, 3, 1};
    auto sql = SQL(names, columns);

    sql.insertRow("two", {"first", "second", "third"});
    REQUIRE("third" == sql.selectCell("two", 1, 3));
    sql.insertRow("two", {"fourth", "fifth", "sixth"});
    sql.deleteRow("two", 1);
    REQUIRE("fifth" == sql.selectCell("two", 2, 2));
  }
}
