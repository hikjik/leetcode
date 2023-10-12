#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string path;
    std::string expected;
  };

  std::vector<TestCase> test_cases{
      {
          .path = "/home/",
          .expected = "/home",
      },
      {
          .path = "/../",
          .expected = "/",
      },
      {
          .path = "/home//foo/",
          .expected = "/home/foo",
      },
  };

  for (const auto &[path, expected] : test_cases) {
    const auto actual = Solution::simplifyPath(path);
    REQUIRE(expected == actual);
  }
}
