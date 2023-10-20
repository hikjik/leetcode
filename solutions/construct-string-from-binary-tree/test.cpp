#include <catch.hpp>

#include <solution.hpp>

#include <tree_node.h>

TEST_CASE("Simple") {
  struct TestCase {
    Tree root;std::string expected;
  };

  std::vector<TestCase> test_cases{
      {.root={1,2,3,4},.expected="1(2(4))(3)",},{.root={1,2,3,std::nullopt,4},.expected="1(2()(4))(3)",},
  };

  for (const auto &[root,expected] : test_cases) {
    const auto actual = Solution::tree2str(root);
    REQUIRE(expected == actual);
  }
}
