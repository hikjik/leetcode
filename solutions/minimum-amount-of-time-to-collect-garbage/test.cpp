#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<std::string> garbage;
    std::vector<int> travel;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .garbage{"G", "P", "GP", "GG"},
          .travel{2, 4, 3},
          .expected = 21,
      },
      {
          .garbage{"MMM", "PGM", "GP"},
          .travel{3, 10},
          .expected = 37,
      },
  };

  for (const auto &[garbage, travel, expected] : test_cases) {
    const auto actual = Solution::garbageCollection(garbage, travel);
    REQUIRE(expected == actual);
  }
}
