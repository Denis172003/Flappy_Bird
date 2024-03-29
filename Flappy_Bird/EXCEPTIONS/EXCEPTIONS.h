// EXCEPTIONS.h

#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <stdexcept>
#include <string>

class FlappyBirdException : public std::exception {
public:
    explicit FlappyBirdException(std::string customMessage);
    [[nodiscard]] const char* what() const noexcept override;

protected:
    std::string message;
};

class WindowClosedException : public FlappyBirdException {
public:
    WindowClosedException();
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

class PlayerTextureLoadException : public FlappyBirdException {
public:
    explicit PlayerTextureLoadException(const std::string& message);
};

class GameOverException : public FlappyBirdException {
public:
    GameOverException();
};

class ObstacleTextureLoadException : public FlappyBirdException {
public:
    explicit ObstacleTextureLoadException(const std::string& message);
};

class ObstacleInvalidPositionException : public FlappyBirdException {
public:
    explicit ObstacleInvalidPositionException(const std::string& message);
};



#endif // EXCEPTIONS_H
