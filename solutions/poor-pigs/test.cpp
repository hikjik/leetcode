#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    int buckets;
    int minutesToDie;
    int minutesToTest;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .buckets = 4,
          .minutesToDie = 15,
          .minutesToTest = 30,
          .expected = 2,
      },
      {
          .buckets = 4,
          .minutesToDie = 15,
          .minutesToTest = 15,
          .expected = 2,
      },
  };

  for (const auto &[buckets, minutesToDie, minutesToTest, expected] :
       test_cases) {
    const auto actual =
        Solution::poorPigs(buckets, minutesToDie, minutesToTest);
    REQUIRE(expected == actual);
  }
}
