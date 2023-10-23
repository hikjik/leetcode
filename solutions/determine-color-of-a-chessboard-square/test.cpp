#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string coordinates;
    bool expected;
  };

  std::vector<TestCase> test_cases{
      {
          .coordinates = "a1",
          .expected = false,
      },
      {
          .coordinates = "h3",
          .expected = true,
      },
      {
          .coordinates = "c7",
          .expected = false,
      },
  };

  for (const auto &[coordinates, expected] : test_cases) {
    const auto actual = Solution::squareIsWhite(coordinates);
    REQUIRE(expected == actual);
  }
}
