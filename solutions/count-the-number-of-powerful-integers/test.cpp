#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    long long start;
    long long finish;
    int limit;
    std::string s;
    long long expected;
  };

  std::vector<TestCase> test_cases{
      {
          .start = 15,
          .finish = 58215,
          .limit = 6,
          .s = "10",
          .expected = 293,
      },
      {
          .start = 1,
          .finish = 6000,
          .limit = 4,
          .s = "124",
          .expected = 5,
      },
      {
          .start = 15,
          .finish = 215,
          .limit = 6,
          .s = "10",
          .expected = 2,
      },
      {
          .start = 1000,
          .finish = 2000,
          .limit = 4,
          .s = "3000",
          .expected = 0,
      },
  };

  for (const auto &[start, finish, limit, s, expected] : test_cases) {
    const auto actual = Solution::numberOfPowerfulInt(start, finish, limit, s);
    REQUIRE(expected == actual);
  }
}
