#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    SnapshotArray snapshot_array(3);
    snapshot_array.set(0, 5);
    REQUIRE(0 == snapshot_array.snap());
    snapshot_array.set(0, 6);
    REQUIRE(5 == snapshot_array.get(0, 0));
  }
  {
    SnapshotArray snapshot_array(1);
    snapshot_array.set(0, 15);
    REQUIRE(0 == snapshot_array.snap());
    REQUIRE(1 == snapshot_array.snap());
    REQUIRE(2 == snapshot_array.snap());
    REQUIRE(15 == snapshot_array.get(0, 2));
    REQUIRE(3 == snapshot_array.snap());
    REQUIRE(4 == snapshot_array.snap());
    REQUIRE(15 == snapshot_array.get(0, 0));
  }
}
