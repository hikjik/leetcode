#pragma once

#include <map>
#include <vector>

/*
  1146. Snapshot Array
  https://leetcode.com/problems/snapshot-array/
  Difficulty: Medium
  Tags: Array, Hash Table, Binary Search, Design
  Time:
  Space:
*/

class SnapshotArray {
private:
  std::vector<std::map<int, int, std::greater<int>>> snapshots_;
  int id_;

public:
  SnapshotArray(int length) : snapshots_(length), id_(0) {}

  void set(int index, int val) { snapshots_[index][id_] = val; }

  int snap() { return id_++; }

  int get(int index, int snap_id) {
    return snapshots_[index].lower_bound(snap_id)->second;
  }
};
