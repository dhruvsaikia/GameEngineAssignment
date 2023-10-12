#include "Component.h"
#include <iostream> // Include the necessary header for console output

Component::Component(int id) : id(id) {
    // Constructor
    std::cout << "Component Created (ID: " << id << ")" << std::endl;
}

Component::~Component() {
    // Destructor
    Destroy();
    std::cout << "Component Destroyed (ID: " << id << ")" << std::endl;
}

void Component::Initialize() {
    // Initialize the component
    std::cout << "Component Initialized (ID: " << id << ")" << std::endl;
}

void Component::Destroy() {
    // Cleanup resources, release resources, etc.
    std::cout << "Component Destroyed (ID: " << id << ")" << std::endl;
}

void Component::Update() {
    // Handle component-specific updates
}

int Component::GetComponentId() const {
    return id;
}
