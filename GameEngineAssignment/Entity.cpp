#include "Entity.h"
#include "Component.h" 
#include <iostream> 

Entity::Entity(const std::string& name) : name(name) {
    std::cout << "Entity '" << name << "' Created" << std::endl;
}

Entity::~Entity() {
    Destroy();
    std::cout << "Entity '" << name << "' Destroyed" << std::endl;
}

void Entity::Initialize() {
    std::cout << "Entity '" << name << "' Initialized" << std::endl;
}

void Entity::Destroy() {
    std::cout << "Entity '" << name << "' Destroyed" << std::endl;
}

void Entity::Update() {
}

void Entity::Load(const std::string& entitySettingsFile) {
    std::cout << "Loading entity settings from: " << entitySettingsFile << std::endl;
}

void Entity::AddComponent(Component* component) {
}

void Entity::RemoveComponent(Component* component) {
}

const std::string& Entity::GetName() const {
    return name;
}