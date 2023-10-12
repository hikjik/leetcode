#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string command;
    std::string expected;
  };

  std::vector<TestCase> test_cases{
      {
          .command = "G()(al)",
          .expected = "Goal",
      },
      {
          .command = "G()()()()(al)",
          .expected = "Gooooal",
      },
      {
          .command = "(al)G(al)()()G",
          .expected = "alGalooG",
      },
  };

  for (const auto &[command, expected] : test_cases) {
    const auto actual = Solution::interpret(command);
    REQUIRE(expected == actual);
  }
}
