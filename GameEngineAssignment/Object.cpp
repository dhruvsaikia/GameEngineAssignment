#include "Object.h"
#include <iostream> // Include the necessary header for console output

Object::Object() {
    // Constructor
    std::cout << "Object Created" << std::endl;
}

Object::~Object() {
    // Destructor
    Destroy();
    std::cout << "Object Destroyed" << std::endl;
}

void Object::Initialize() {
    // Initialize the object, set up any initial state, etc.
    std::cout << "Object Initialized" << std::endl;
}

void Object::Destroy() {
    // Cleanup resources, release any acquired resources, etc.
    std::cout << "Object Destroyed" << std::endl;
}

bool Object::IsInitialized() const {
    // Return whether the object is initialized or not
    // You can implement this based on your specific requirements
    return false;
}
