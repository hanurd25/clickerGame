#pragma once
#include <vector>

namespace CakeClicker {
    void addScore(int points);
    double getScore();
    void buyUpgrade(int upgradeId);
    double getClickMultiplier();
    double getPassiveIncome();
    void update(double deltaTime);   // for auto‑increment
    void reset();
}