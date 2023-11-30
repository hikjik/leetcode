#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<std::string> bank;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .bank{"011001", "000000", "010100", "001000"},
          .expected = 8,
      },
      {
          .bank{"000", "111", "000"},
          .expected = 0,
      },
  };

  for (const auto &[bank, expected] : test_cases) {
    const auto actual = Solution::numberOfBeams(bank);
    REQUIRE(expected == actual);
  }
}
