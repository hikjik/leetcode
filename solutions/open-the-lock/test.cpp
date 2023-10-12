#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<std::string> deadends;
    std::string target;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .deadends{"0201", "0101", "0102", "1212", "2002"},
          .target = "0202",
          .expected = 6,
      },
      {
          .deadends{"8888"},
          .target = "0009",
          .expected = 1,
      },
      {
          .deadends{"8887", "8889", "8878", "8898", "8788", "8988", "7888",
                    "9888"},
          .target = "8888",
          .expected = -1,
      },
  };

  for (const auto &[deadends, target, expected] : test_cases) {
    const auto actual = Solution::openLock(deadends, target);
    REQUIRE(expected == actual);
  }
}
