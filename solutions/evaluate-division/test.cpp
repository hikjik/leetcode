#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<std::vector<std::string>> equations;
    std::vector<double> values;
    std::vector<std::vector<std::string>> queries;
    std::vector<double> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .equations{{"a", "b"}, {"b", "c"}},
          .values{2.0, 3.0},
          .queries{{"a", "c"}, {"b", "a"}, {"a", "e"}, {"a", "a"}, {"x", "x"}},
          .expected{6.00000, 0.50000, -1.00000, 1.00000, -1.00000},
      },
      {
          .equations{{"a", "b"}, {"b", "c"}, {"bc", "cd"}},
          .values{1.5, 2.5, 5.0},
          .queries{{"a", "c"}, {"c", "b"}, {"bc", "cd"}, {"cd", "bc"}},
          .expected{3.75000, 0.40000, 5.00000, 0.20000},
      },
      {
          .equations{{"a", "b"}},
          .values{0.5},
          .queries{{"a", "b"}, {"b", "a"}, {"a", "c"}, {"x", "y"}},
          .expected{0.50000, 2.00000, -1.00000, -1.00000},
      },
  };

  for (const auto &[equations, values, queries, expected] : test_cases) {
    const auto actual = Solution::calcEquation(equations, values, queries);
    REQUIRE(expected == actual);
  }
}
