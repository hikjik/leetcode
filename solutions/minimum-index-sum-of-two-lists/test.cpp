#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<std::string> list1;
    std::vector<std::string> list2;
    std::vector<std::string> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .list1{"Shogun", "Tapioca Express", "Burger King", "KFC"},
          .list2{"Piatti", "The Grill at Torrey Pines",
                 "Hungry Hunter Steakhouse", "Shogun"},
          .expected{"Shogun"},
      },
      {
          .list1{"Shogun", "Tapioca Express", "Burger King", "KFC"},
          .list2{"KFC", "Shogun", "Burger King"},
          .expected{"Shogun"},
      },
      {
          .list1{"happy", "sad", "good"},
          .list2{"sad", "happy", "good"},
          .expected{"sad", "happy"},
      },
  };

  for (const auto &[list1, list2, expected] : test_cases) {
    const auto actual = Solution::findRestaurant(list1, list2);
    REQUIRE(expected == actual);
  }
}
