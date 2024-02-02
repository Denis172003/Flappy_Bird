
#ifndef OOP_GAMESETTINGS_H
#define OOP_GAMESETTINGS_H
#pragma once

class GameSettings {
private:
    int screenWidth;
    int screenHeight;
    static GameSettings* instance;

    GameSettings();

public:

    GameSettings(const GameSettings&) = delete;
    GameSettings& operator=(const GameSettings&) = delete;

    static GameSettings* getInstance();

    [[nodiscard]] int getScreenWidth() const;
    [[nodiscard]] int getScreenHeight() const;
    void setScreenWidth(int width);
    void setScreenHeight(int height);
};
#endif //OOP_GAMESETTINGS_H
