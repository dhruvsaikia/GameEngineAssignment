#include "Entity.h"
#include "Component.h"
#include <iostream>
#include "json.hpp"

Entity::Entity(const std::string& name) : name(name) {
    std::cout << "Entity Create" << std::endl;
}

Entity::~Entity() {
    std::cout << "Entity '" << name << "' Destructor" << std::endl;
    for (auto comp : components) {
        delete comp;
    }
    components.clear();
}

void Entity::Initialize() {
    std::cout << "Entity " << name << " Initialize" << std::endl;
    for (auto comp : components) {
        comp->Initialize();
    }
}

void Entity::Destroy() {
    std::cout << "Entity '" << name << "' Destroyed" << std::endl;
}

void Entity::Update() {
    std::cout << "Entity " << name << " Update" << std::endl;
    for (auto comp : components) {
        comp->Update();
    }
}

void Entity::Load(const json::JSON& entityData) {
    std::cout << "Entity Load" << std::endl;

    if (entityData.hasKey("Components")) {
        auto& components = const_cast<json::JSON&>(entityData)["Components"];
        for (auto& componentData : components.ArrayRange()) {
            if (componentData.hasKey("id")) {
                int id = componentData["id"].ToInt();
                Component* newComponent = new Component(id);
                newComponent->Load(const_cast<json::JSON&>(componentData));
                this->components.push_back(newComponent);
            }
        }
    }
}

void Entity::AddComponent(Component* component) {
    components.push_back(component);
}

void Entity::RemoveComponent(Component* component) {
    components.remove(component);
    delete component;
}

const std::string& Entity::GetName() const {
    return name;
}
