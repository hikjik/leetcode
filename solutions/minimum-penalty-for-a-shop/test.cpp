#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string customers;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .customers = "YYNY",
          .expected = 2,
      },
      {
          .customers = "NNNNN",
          .expected = 0,
      },
      {
          .customers = "YYYY",
          .expected = 4,
      },
  };

  for (const auto &[customers, expected] : test_cases) {
    const auto actual = Solution::bestClosingTime(customers);
    REQUIRE(expected == actual);
  }
}
