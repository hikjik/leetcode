#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<std::vector<std::string>> paths;
    std::string expected;
  };

  std::vector<TestCase> test_cases{
      {
          .paths{{"London", "New York"},
                 {"New York", "Lima"},
                 {"Lima", "Sao Paulo"}},
          .expected = "Sao Paulo",
      },
      {
          .paths{{"B", "C"}, {"D", "B"}, {"C", "A"}},
          .expected = "A",
      },
      {
          .paths{{"A", "Z"}},
          .expected = "Z",
      },
  };

  for (const auto &[paths, expected] : test_cases) {
    const auto actual = Solution::destCity(paths);
    REQUIRE(expected == actual);
  }
}
