#pragma once
#include <exception>
#include <string>

class FlappyBirdException : public std::exception {
private:
    std::string message;
public:
    explicit FlappyBirdException() : message("FlappyBirdException occurred") {}

    [[nodiscard]] const char* what() const noexcept override {
        return message.c_str();
    }

    void setMessage(const std::string& message1) {
        this->message = message1;
    }

};

class BirdCollisionException : public FlappyBirdException {
public:
    explicit BirdCollisionException() : FlappyBirdException() {
        setMessage("BirdCollisionException occurred");
    }
};

class BirdOutOfScreenException : public FlappyBirdException {
public:
    explicit BirdOutOfScreenException() : FlappyBirdException() {
        setMessage("BirdOutOfScreenException occurred");
    }
};

class GameOverException : public FlappyBirdException {
public:
    explicit GameOverException() : FlappyBirdException() {
        setMessage("GameOverException occurred");
    }
};