#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums;std::vector<int> divisors;int expected;
  };

  std::vector<TestCase> test_cases{
      {.nums{4,7,9,3,9},.divisors{5,2,3},.expected=3,},{.nums{20,14,21,10},.divisors{5,7,5},.expected=5,},{.nums{12},.divisors{10,16},.expected=10,},
  };

  for (const auto &[nums,divisors,expected] : test_cases) {
    const auto actual = Solution::maxDivScore(nums, divisors);
    REQUIRE(expected == actual);
  }
}
