#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    std::vector<int> nums{2, 3, 5};
    auto first_unique = FirstUnique(nums);

    REQUIRE(2 == first_unique.showFirstUnique());
    first_unique.add(5);
    REQUIRE(2 == first_unique.showFirstUnique());
    first_unique.add(2);
    REQUIRE(3 == first_unique.showFirstUnique());
    first_unique.add(3);
    REQUIRE(-1 == first_unique.showFirstUnique());
  }
  {
    std::vector<int> nums{7, 7, 7, 7, 7, 7};
    auto first_unique = FirstUnique(nums);

    REQUIRE(-1 == first_unique.showFirstUnique());
    first_unique.add(7);
    first_unique.add(3);
    first_unique.add(3);
    first_unique.add(7);
    first_unique.add(17);
    REQUIRE(17 == first_unique.showFirstUnique());
  }
  {
    std::vector<int> nums{809};
    auto first_unique = FirstUnique(nums);

    REQUIRE(809 == first_unique.showFirstUnique());
    first_unique.add(809);
    REQUIRE(-1 == first_unique.showFirstUnique());
  }
}
