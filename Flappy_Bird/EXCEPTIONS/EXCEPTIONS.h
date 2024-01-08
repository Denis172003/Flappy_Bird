// EXCEPTIONS.h

#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <stdexcept>
#include <string>

class FlappyBirdException : public std::exception {
public:
    FlappyBirdException(const std::string& customMessage);
    const char* what() const noexcept override;

protected:
    std::string message;
};

class WindowClosedException : public FlappyBirdException {
public:
    WindowClosedException();
};

class InvalidInputException : public FlappyBirdException {
public:
    InvalidInputException(const std::string& input);
};

class RestartFailedException : public FlappyBirdException {
public:
    RestartFailedException();
};

class BirdCollisionException : public FlappyBirdException {
public:
    BirdCollisionException();
};

class BirdOutOfScreenException : public FlappyBirdException {
public:
    BirdOutOfScreenException();
};

class GameOverException : public FlappyBirdException {
public:
    GameOverException();
};

#endif // EXCEPTIONS_H
