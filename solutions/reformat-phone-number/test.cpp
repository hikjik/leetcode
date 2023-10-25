#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string number;
    std::string expected;
  };

  std::vector<TestCase> test_cases{
      {
          .number = "1-23-45 6",
          .expected = "123-456",
      },
      {
          .number = "123 4-567",
          .expected = "123-45-67",
      },
      {
          .number = "123 4-5678",
          .expected = "123-456-78",
      },
  };

  for (const auto &[number, expected] : test_cases) {
    const auto actual = Solution::reformatNumber(number);
    REQUIRE(expected == actual);
  }
}
