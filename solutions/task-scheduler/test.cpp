#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    int n = 2;
    std::vector<char> tasks{'A', 'A', 'A', 'B', 'B', 'B'};
    REQUIRE(8 == Solution::leastInterval(tasks, n));
  }
  {
    int n = 0;
    std::vector<char> tasks{'A', 'A', 'A', 'B', 'B', 'B'};
    REQUIRE(6 == Solution::leastInterval(tasks, n));
  }
  {
    int n = 2;
    std::vector<char> tasks{'A', 'A', 'A', 'A', 'A', 'A',
                            'B', 'C', 'D', 'E', 'F', 'G'};
    REQUIRE(16 == Solution::leastInterval(tasks, n));
  }
}
