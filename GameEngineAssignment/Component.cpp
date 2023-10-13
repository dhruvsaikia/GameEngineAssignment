#include "Component.h"
#include <iostream>

Component::Component(int id) : id(id) {
    std::cout << "Component Created (ID: " << id << ")" << std::endl;
}

Component::~Component() {
    Destroy();
    std::cout << "Component Destroyed (ID: " << id << ")" << std::endl;
}

void Component::Initialize() {
    std::cout << "Component Initialized (ID: " << id << ")" << std::endl;
}

void Component::Destroy() {
    std::cout << "Component Destroyed (ID: " << id << ")" << std::endl;
}

void Component::Update() {
}

int Component::GetComponentId() const {
    return id;
}
