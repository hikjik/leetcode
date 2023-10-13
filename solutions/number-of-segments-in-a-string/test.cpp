#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string s;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .s = "Hello, my name is John",
          .expected = 5,
      },
      {
          .s = "Hello",
          .expected = 1,
      },
  };

  for (const auto &[s, expected] : test_cases) {
    const auto actual = Solution::countSegments(s);
    REQUIRE(expected == actual);
  }
}
