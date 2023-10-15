#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string num;
    std::string expected;
  };

  std::vector<TestCase> test_cases{
      {
          .num = "51230100",
          .expected = "512301",
      },
      {
          .num = "123",
          .expected = "123",
      },
  };

  for (const auto &[num, expected] : test_cases) {
    const auto actual = Solution::removeTrailingZeros(num);
    REQUIRE(expected == actual);
  }
}
