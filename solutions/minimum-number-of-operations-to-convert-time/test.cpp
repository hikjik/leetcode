#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string current;
    std::string correct;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .current = "02:30",
          .correct = "04:35",
          .expected = 3,
      },
      {
          .current = "11:00",
          .correct = "11:01",
          .expected = 1,
      },
  };

  for (const auto &[current, correct, expected] : test_cases) {
    const auto actual = Solution::convertTime(current, correct);
    REQUIRE(expected == actual);
  }
}
