#include "InputManager.h"
#include <iostream>

InputManager::InputManager() {
    std::cout << "InputManager Created" << std::endl;
}

InputManager::~InputManager() {
    Destroy();
    std::cout << "InputManager Destroyed" << std::endl;
}

void InputManager::Initialize() {
    std::cout << "InputManager Initialized" << std::endl;
}

void InputManager::Destroy() {
    std::cout << "InputManager Destroyed" << std::endl;
}

void InputManager::Update() {
}
