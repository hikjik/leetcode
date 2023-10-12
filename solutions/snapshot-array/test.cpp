#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  int length = 3;
  auto snapshot_array = SnapshotArray(length);

  snapshot_array.set(0, 5);
  REQUIRE(0 == snapshot_array.snap());
  snapshot_array.set(0, 6);
  REQUIRE(5 == snapshot_array.get(0, 0));
}
