#include "Object.h"
#include <iostream> 

Object::Object() {
    std::cout << "Object Created" << std::endl;
}

Object::~Object() {
    Destroy();
    std::cout << "Object Destroyed" << std::endl;
}

void Object::Initialize() {
    std::cout << "Object Initialized" << std::endl;
}

void Object::Destroy() {
    std::cout << "Object Destroyed" << std::endl;
}

bool Object::IsInitialized() const {
    return false;
}
