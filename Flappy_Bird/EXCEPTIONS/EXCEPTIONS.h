#pragma once
#include <exception>
#include <string>

class FlappyBirdException : public std::exception {
private:
    std::string message;

public:
    explicit FlappyBirdException();
    ~FlappyBirdException() noexcept override = default;

    [[nodiscard]] const char* what() const noexcept override;

    void setMessage(const std::string& message1);
};

class BirdCollisionException : public FlappyBirdException {
public:
    explicit BirdCollisionException();
};

class BirdOutOfScreenException : public FlappyBirdException {
public:
    explicit BirdOutOfScreenException();
};

class GameOverException : public FlappyBirdException {
public:
    explicit GameOverException();
};
