#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> pid;
    std::vector<int> ppid;
    int kill;
    std::vector<int> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .pid{1, 3, 10, 5},
          .ppid{3, 0, 5, 3},
          .kill = 5,
          .expected{5, 10},
      },
      {
          .pid{1},
          .ppid{0},
          .kill = 1,
          .expected{1},
      },
  };

  for (const auto &[pid, ppid, kill, expected] : test_cases) {
    const auto actual = Solution::killProcess(pid, ppid, kill);
    REQUIRE(expected == actual);
  }
}
