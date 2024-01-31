// GameSettings.cpp
#include "GameSettings.h"


GameSettings* GameSettings::instance = nullptr;

GameSettings::GameSettings()
        : screenWidth(800), screenHeight(600) {

}

GameSettings* GameSettings::getInstance() {

    if (instance == nullptr) {
        instance = new GameSettings();
    }
    return instance;
}

int GameSettings::getScreenWidth() const {
    return screenWidth;
}

int GameSettings::getScreenHeight() const {
    return screenHeight;
}

void GameSettings::setScreenWidth(int width) {
    screenWidth = width;
}

void GameSettings::setScreenHeight(int height) {
    screenHeight = height;
}
