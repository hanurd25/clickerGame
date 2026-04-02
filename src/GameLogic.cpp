#include "GameLogic.h"
#include <emscripten/bind.h>

namespace CakeClicker {
    static double score = 0.0;
    static double clickMultiplier = 1.0;
    static double passivePerSecond = 0.0;
    static double timeAccumulator = 0.0;

    void addScore(int points) {
        score += points * clickMultiplier;
    }

    double getScore() { return score; }

    void buyUpgrade(int id) {
        if (id == 0 && score >= 10.0) {   // upgrade: +1 click multiplier
            score -= 10.0;
            clickMultiplier += 1.0;
        }
        else if (id == 1 && score >= 50.0) { // passive income: +0.5 per sec
            score -= 50.0;
            passivePerSecond += 0.5;
        }
    }

    double getClickMultiplier() { return clickMultiplier; }
    double getPassiveIncome() { return passivePerSecond; }

    void update(double deltaTime) {
        timeAccumulator += deltaTime;
        if (timeAccumulator >= 1.0) {
            score += passivePerSecond;
            timeAccumulator = 0.0;
        }
    }

    void reset() {
        score = 0.0;
        clickMultiplier = 1.0;
        passivePerSecond = 0.0;
        timeAccumulator = 0.0;
    }
}

// Embind bindings – this is what makes C++ functions callable from JS
EMSCRIPTEN_BINDINGS(cake_clicker) {
    emscripten::function("addScore", &CakeClicker::addScore);
    emscripten::function("getScore", &CakeClicker::getScore);
    emscripten::function("buyUpgrade", &CakeClicker::buyUpgrade);
    emscripten::function("getClickMultiplier", &CakeClicker::getClickMultiplier);
    emscripten::function("getPassiveIncome", &CakeClicker::getPassiveIncome);
    emscripten::function("update", &CakeClicker::update);
    emscripten::function("reset", &CakeClicker::reset);
}