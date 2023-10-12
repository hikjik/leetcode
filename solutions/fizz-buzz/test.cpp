#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    int n;
    std::vector<std::string> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .n = 3,
          .expected{"1", "2", "Fizz"},
      },
      {
          .n = 5,
          .expected{"1", "2", "Fizz", "4", "Buzz"},
      },
      {
          .n = 15,
          .expected{"1", "2", "Fizz", "4", "Buzz", "Fizz", "7", "8", "Fizz",
                    "Buzz", "11", "Fizz", "13", "14", "FizzBuzz"},
      },
  };

  for (const auto &[n, expected] : test_cases) {
    const auto actual = Solution::fizzBuzz(n);
    REQUIRE(expected == actual);
  }
}
