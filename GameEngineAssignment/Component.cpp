#include "Component.h"
#include <iostream>

Component::Component(int id) : id(id) {
    std::cout << "Component Create (ID: " << id << ")" << std::endl;
}

Component::~Component() {
    std::cout << "Component<Component> " << id << " Destructor" << std::endl;
}

void Component::Initialize() {
    std::cout << "Component<Component> " << id << " Initialize" << std::endl;
}

void Component::Destroy() {
    std::cout << "Component<Component> " << id << " Destroy" << std::endl;
}

void Component::Update() {
    std::cout << "Component<Component> " << id << " Update" << std::endl;
}

int Component::GetComponentId() const {
    return id;
}
