#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string s;
    std::string expected;
  };

  std::vector<TestCase> test_cases{
      {
          .s = "Hello",
          .expected = "hello",
      },
      {
          .s = "here",
          .expected = "here",
      },
      {
          .s = "LOVELY",
          .expected = "lovely",
      },
  };

  for (const auto &[s, expected] : test_cases) {
    const auto actual = Solution::toLowerCase(s);
    REQUIRE(expected == actual);
  }
}
