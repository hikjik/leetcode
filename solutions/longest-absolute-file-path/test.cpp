#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string input;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .input = "dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext",
          .expected = 20,
      },
      {
          .input =
              "dir\n\tsubdir1\n\t\tfile1."
              "ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext",
          .expected = 32,
      },
      {
          .input = "a",
          .expected = 0,
      },
  };

  for (const auto &[input, expected] : test_cases) {
    const auto actual = Solution::lengthLongestPath(input);
    REQUIRE(expected == actual);
  }
}
