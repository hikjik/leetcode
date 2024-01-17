#include <catch.hpp>

#include <solution.hpp>

#include <cstring>

TEST_CASE("Simple") {
  struct TestCase {
    std::string file;
    int n;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .file = "abc",
          .n = 4,
          .expected = 3,
      },
      {
          .file = "abcde",
          .n = 5,
          .expected = 5,
      },
      {
          .file = "abcdABCD1234",
          .n = 12,
          .expected = 12,
      },
      {
          .file = "leetcode",
          .n = 5,
          .expected = 5,
      },
  };

  for (const auto &[file, n, expected] : test_cases) {
    auto *src = file.data();
    read4 = [&](char *dst) {
      const auto res = std::min<int>(4, std::strlen(src));
      std::strncpy(dst, src, res);
      src += res;
      return res;
    };

    char *buf = new char[n];
    REQUIRE(expected == Solution::read(buf, n));
    REQUIRE(0 == std::strncmp(file.data(), buf, expected));
    delete[] buf;
  }
}
