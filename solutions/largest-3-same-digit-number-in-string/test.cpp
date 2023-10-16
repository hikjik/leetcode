#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string num;
    std::string expected;
  };

  std::vector<TestCase> test_cases{
      {
          .num = "6777133339",
          .expected = "777",
      },
      {
          .num = "2300019",
          .expected = "000",
      },
      {
          .num = "42352338",
          .expected = "",
      },
  };

  for (const auto &[num, expected] : test_cases) {
    const auto actual = Solution::largestGoodInteger(num);
    REQUIRE(expected == actual);
  }
}
