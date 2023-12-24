#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string source;
    std::string target;
    std::vector<char> original;
    std::vector<char> changed;
    std::vector<int> cost;
    long long expected;
  };

  std::vector<TestCase> test_cases{
      {
          .source = "abcd",
          .target = "acbe",
          .original{'a', 'b', 'c', 'c', 'e', 'd'},
          .changed{'b', 'c', 'b', 'e', 'b', 'e'},
          .cost{2, 5, 5, 1, 2, 20},
          .expected = 28,
      },
      {
          .source = "aaaa",
          .target = "bbbb",
          .original{'a', 'c'},
          .changed{'c', 'b'},
          .cost{1, 2},
          .expected = 12,
      },
      {
          .source = "abcd",
          .target = "abce",
          .original{'a'},
          .changed{'e'},
          .cost{10000},
          .expected = -1,
      },
  };

  for (const auto &[source, target, original, changed, cost, expected] :
       test_cases) {
    const auto actual =
        Solution::minimumCost(source, target, original, changed, cost);
    REQUIRE(expected == actual);
  }
}
