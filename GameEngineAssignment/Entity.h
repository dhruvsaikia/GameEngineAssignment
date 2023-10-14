#pragma once

#include <list>
#include <string>
#include <algorithm>
#include "Component.h"

class Entity {
public:
    Entity(const std::string& name);
    ~Entity();

    void Initialize();
    void Destroy();
    void Update();
    void Load(const std::string& entitySettingsFile);

    void AddComponent(Component* component);
    void RemoveComponent(Component* component);
    const std::string& GetName() const;

private:
    std::string name;
    std::list<Component*> components;
};
