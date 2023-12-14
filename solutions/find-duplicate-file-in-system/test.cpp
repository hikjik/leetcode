#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<std::string> paths;
    std::vector<std::vector<std::string>> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .paths{"root/a 1.txt(abcd) 2.txt(efgh)", "root/c 3.txt(abcd)",
                 "root/c/d 4.txt(efgh)", "root 4.txt(efgh)"},
          .expected{{"root/a/2.txt", "root/c/d/4.txt", "root/4.txt"},
                    {"root/a/1.txt", "root/c/3.txt"}},
      },
      {
          .paths{"root/a 1.txt(abcd) 2.txt(efgh)", "root/c 3.txt(abcd)",
                 "root/c/d 4.txt(efgh)"},
          .expected{{"root/a/2.txt", "root/c/d/4.txt"},
                    {"root/a/1.txt", "root/c/3.txt"}},
      },
  };

  for (const auto &[paths, expected] : test_cases) {
    const auto actual = Solution::findDuplicate(paths);
    REQUIRE(expected == actual);
  }
}
