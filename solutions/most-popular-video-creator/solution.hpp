#pragma once

#include <ranges>
#include <string>
#include <unordered_map>
#include <vector>

// Time: O(N)
// Space: O(N)

class Solution {
public:
  struct Video {
    std::string id;
    int views;
  };

  struct Creator {
    long long popularity;
    Video mostPopularVideo;
  };

  static std::vector<std::vector<std::string>>
  mostPopularCreator(const std::vector<std::string> &creators,
                     const std::vector<std::string> &ids,
                     const std::vector<int> &views) {
    std::unordered_map<std::string, Creator> nameToCreator;
    long long maxPopularity = 0;
    for (int i = 0; i < std::ssize(creators); ++i) {
      auto &creator = nameToCreator[creators[i]];
      creator.popularity += views[i];
      maxPopularity = std::max(maxPopularity, creator.popularity);

      auto &video = creator.mostPopularVideo;
      if (video.id.empty() || video.views < views[i] ||
          (video.views == views[i] && video.id > ids[i])) {
        video = {ids[i], views[i]};
      }
    }

    std::vector<std::vector<std::string>> ans;
    for (const auto &[name, creator] : nameToCreator) {
      if (creator.popularity == maxPopularity) {
        ans.push_back({name, creator.mostPopularVideo.id});
      }
    }
    return ans;
  }
};
