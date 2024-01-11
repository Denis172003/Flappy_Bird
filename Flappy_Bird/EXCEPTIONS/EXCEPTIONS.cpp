
#include "EXCEPTIONS.h"

#include <utility>

FlappyBirdException::FlappyBirdException(std::string  customMessage)
        : message(std::move(customMessage)) {}

const char* FlappyBirdException::what() const noexcept {
    return message.c_str();
}

WindowClosedException::WindowClosedException()
        : FlappyBirdException("Window was closed during event handling") {}

RestartFailedException::RestartFailedException()
        : FlappyBirdException("Failed to restart the game") {}

BirdCollisionException::BirdCollisionException()
        : FlappyBirdException("BirdCollisionException occurred") {}

BirdOutOfScreenException::BirdOutOfScreenException()
        : FlappyBirdException("BirdOutOfScreenException occurred") {}

GameOverException::GameOverException()
        : FlappyBirdException("GameOverException occurred") {}

ObstacleTextureLoadException::ObstacleTextureLoadException(const std::string& message)
        : FlappyBirdException(message) {}

ObstacleInvalidPositionException::ObstacleInvalidPositionException(const std::string& message)
        : FlappyBirdException(message) {}