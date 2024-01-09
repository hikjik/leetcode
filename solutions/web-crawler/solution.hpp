#pragma once

#include <queue>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

// Time:
// Space:

class HtmlParser {
public:
  HtmlParser(const std::vector<std::string> &urls,
             const std::vector<std::vector<int>> &edges)
      : urls(urls), graph(urls.size()) {
    for (int i = 0; i < std::ssize(urls); ++i) {
      urlToID[urls[i]] = i;
    }
    for (const auto &edge : edges) {
      graph[edge[0]].push_back(edge[1]);
    }
  }

  std::vector<std::string> getUrls(std::string url) {
    std::vector<std::string> res;
    for (auto v : graph[urlToID[url]]) {
      res.push_back(urls[v]);
    }
    return res;
  }

private:
  std::vector<std::string> urls;
  std::vector<std::vector<int>> graph;
  std::unordered_map<std::string, int> urlToID;
};

class Solution {
public:
  static std::vector<std::string> crawl(std::string startUrl,
                                        HtmlParser &htmlParser) {
    std::unordered_set<std::string> seen{startUrl};
    std::queue<std::string> queue{{startUrl}};
    while (!queue.empty()) {
      const auto u = queue.front();
      queue.pop();

      for (auto v : htmlParser.getUrls(u)) {
        if (!seen.contains(v) && getHostname(u) == getHostname(v)) {
          seen.insert(v);
          queue.push(v);
        }
      }
    }
    return {seen.begin(), seen.end()};
  }

private:
  static std::string getHostname(const std::string &url) {
    const auto pos = std::min(url.size(), url.find('/', 7));
    return url.substr(7, pos - 7);
  };
};
