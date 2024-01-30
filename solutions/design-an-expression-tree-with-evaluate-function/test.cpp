#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<std::string> s;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .s{"3", "4", "+", "2", "*", "7", "/"},
          .expected = 2,
      },
      {
          .s{"4", "5", "2", "7", "+", "-", "*"},
          .expected = -16,
      },
  };

  for (const auto &[s, expected] : test_cases) {
    auto *actual = TreeBuilder::buildTree(s);
    REQUIRE(expected == actual->evaluate());
  }
}
