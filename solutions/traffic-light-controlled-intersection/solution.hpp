#pragma once

#include <atomic>
#include <functional>
#include <mutex>

// Time:
// Space:

class TrafficLight {
public:
  TrafficLight() : light(1) {}

  void carArrived([[maybe_unused]] int carId, int roadId,
                  [[maybe_unused]] int direction,
                  std::function<void()> turnGreen,
                  std::function<void()> crossCar) {
    std::lock_guard<std::mutex> lg(mutex);
    if (light != roadId) {
      turnGreen();
      light = roadId;
    }
    crossCar();
  }

private:
  std::mutex mutex;
  std::atomic<int> light;
};
