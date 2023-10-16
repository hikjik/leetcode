#pragma once

#include <string>
#include <unordered_set>
#include <vector>

// This is the Master's API interface.
// You should not implement it, or speculate about its implementation
class Master {
public:
  Master(const std::vector<std::string> &words, std::string secret,
         int allowedGuesses)
      : words_(words.begin(), words.end()), secret_(secret),
        allowedGuesses_(allowedGuesses), guessesCount_(0), guessed_(false) {}

  int guess(std::string word) {
    ++guessesCount_;

    if (!words_.contains(word)) {
      return -1;
    }

    guessed_ = word == secret_;

    int cnt = 0;
    for (size_t j = 0; j < word.size(); ++j) {
      cnt += word[j] == secret_[j];
    }
    return cnt;
  }

  std::string message() const {
    if (!guessed_ || guessesCount_ > allowedGuesses_) {
      return "Either you took too many guesses, or you did not find the secret "
             "word.";
    }
    return "You guessed the secret word correctly.";
  }

private:
  std::unordered_set<std::string> words_;
  std::string secret_;
  int allowedGuesses_;
  int guessesCount_;
  bool guessed_;
};

class Solution {
public:
  static void findSecretWord(const std::vector<std::string> &words,
                             Master &master) {
    std::unordered_set<std::string> set(words.begin(), words.end());
    while (set.size() > 1) {
      const auto word = *set.begin();
      const auto matches = master.guess(word);
      for (auto it = set.begin(); it != set.end();) {
        it = matches != getMatches(word, *it) ? set.erase(it) : ++it;
      }
    }
    master.guess(*set.begin());
  }

private:
  static int getMatches(const std::string &first, const std::string &second) {
    int matches = 0;
    for (size_t i = 0; i < first.size(); ++i) {
      if (first[i] == second[i]) {
        ++matches;
      }
    }
    return matches;
  }
};
