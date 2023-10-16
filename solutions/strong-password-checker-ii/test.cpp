#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string password;
    bool expected;
  };

  std::vector<TestCase> test_cases{
      {
          .password = "IloveLe3tcode!",
          .expected = true,
      },
      {
          .password = "Me+You--IsMyDream",
          .expected = false,
      },
      {
          .password = "1aB!",
          .expected = false,
      },
  };

  for (const auto &[password, expected] : test_cases) {
    const auto actual = Solution::strongPasswordCheckerII(password);
    REQUIRE(expected == actual);
  }
}
