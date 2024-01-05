

#include "EXCEPTIONS.h"

FlappyBirdException::FlappyBirdException() : message("FlappyBirdException occurred") {}

const char* FlappyBirdException::what() const noexcept {
    return message.c_str();
}

void FlappyBirdException::setMessage(const std::string& message1) {
    this->message = message1;
}

BirdCollisionException::BirdCollisionException() : FlappyBirdException() {
    setMessage("BirdCollisionException occurred");
}

BirdOutOfScreenException::BirdOutOfScreenException() : FlappyBirdException() {
    setMessage("BirdOutOfScreenException occurred");
}

GameOverException::GameOverException() : FlappyBirdException() {
    setMessage("GameOverException occurred");
}
