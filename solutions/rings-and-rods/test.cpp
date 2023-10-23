#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string rings;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .rings = "B0B6G0R6R0R6G9",
          .expected = 1,
      },
      {
          .rings = "B0R0G0R9R0B0G0",
          .expected = 1,
      },
      {
          .rings = "G4",
          .expected = 0,
      },
  };

  for (const auto &[rings, expected] : test_cases) {
    const auto actual = Solution::countPoints(rings);
    REQUIRE(expected == actual);
  }
}
