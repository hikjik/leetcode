#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    std::string start_gene = "AACCGGTT";
    std::string end_gene = "AACCGGTA";
    std::vector<std::string> bank{"AACCGGTA"};
    REQUIRE(1 == Solution::minMutation(start_gene, end_gene, bank));
  }
  {
    std::string start_gene = "AACCGGTT";
    std::string end_gene = "AAACGGTA";
    std::vector<std::string> bank{"AACCGGTA", "AACCGCTA", "AAACGGTA"};
    REQUIRE(2 == Solution::minMutation(start_gene, end_gene, bank));
  }
}
