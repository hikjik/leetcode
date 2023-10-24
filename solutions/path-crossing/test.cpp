#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string path;
    bool expected;
  };

  std::vector<TestCase> test_cases{
      {
          .path = "NES",
          .expected = false,
      },
      {
          .path = "NESWW",
          .expected = true,
      },
  };

  for (const auto &[path, expected] : test_cases) {
    const auto actual = Solution::isPathCrossing(path);
    REQUIRE(expected == actual);
  }
}
