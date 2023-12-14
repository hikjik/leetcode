#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<std::vector<char>> box;
    std::vector<std::vector<char>> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .box{{'#', '.', '#'}},
          .expected{{'.'}, {'#'}, {'#'}},
      },
      {
          .box{{'#', '.', '*', '.'}, {'#', '#', '*', '.'}},
          .expected{{'#', '.'}, {'#', '#'}, {'*', '*'}, {'.', '.'}},
      },
      {
          .box{{'#', '#', '*', '.', '*', '.'},
               {'#', '#', '#', '*', '.', '.'},
               {'#', '#', '#', '.', '#', '.'}},
          .expected{{'.', '#', '#'},
                    {'.', '#', '#'},
                    {'#', '#', '*'},
                    {'#', '*', '.'},
                    {'#', '.', '*'},
                    {'#', '.', '.'}},
      },
  };

  for (const auto &[box, expected] : test_cases) {
    const auto actual = Solution::rotateTheBox(box);
    REQUIRE(expected == actual);
  }
}
