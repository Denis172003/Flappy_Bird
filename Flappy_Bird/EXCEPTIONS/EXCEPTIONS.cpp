
#include "EXCEPTIONS.h"

FlappyBirdException::FlappyBirdException(const std::string& customMessage)
        : message(customMessage) {}

const char* FlappyBirdException::what() const noexcept {
    return message.c_str();
}

WindowClosedException::WindowClosedException()
        : FlappyBirdException("Window was closed during event handling") {}

InvalidInputException::InvalidInputException(const std::string& input)
        : FlappyBirdException("Invalid input received: " + input) {}

RestartFailedException::RestartFailedException()
        : FlappyBirdException("Failed to restart the game") {}

BirdCollisionException::BirdCollisionException()
        : FlappyBirdException("BirdCollisionException occurred") {}

BirdOutOfScreenException::BirdOutOfScreenException()
        : FlappyBirdException("BirdOutOfScreenException occurred") {}

GameOverException::GameOverException()
        : FlappyBirdException("GameOverException occurred") {}
