#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string source;
    std::string target;
    std::vector<std::string> original;
    std::vector<std::string> changed;
    std::vector<int> cost;
    long long expected;
  };

  std::vector<TestCase> test_cases{
      {
          .source = "abcd",
          .target = "acbe",
          .original{"a", "b", "c", "c", "e", "d"},
          .changed{"b", "c", "b", "e", "b", "e"},
          .cost{2, 5, 5, 1, 2, 20},
          .expected = 28,
      },
      {
          .source = "abcdefgh",
          .target = "acdeeghh",
          .original{"bcd", "fgh", "thh"},
          .changed{"cde", "thh", "ghh"},
          .cost{1, 3, 5},
          .expected = 9,
      },
      {
          .source = "abcdefgh",
          .target = "addddddd",
          .original{"bcd", "defgh"},
          .changed{"ddd", "ddddd"},
          .cost{100, 1578},
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
