#pragma once

#include <list>
#include <string>

class Component; // Forward declaration of the Component class

class Entity {
public:
    Entity(const std::string& name);
    ~Entity();

    void Initialize();
    void Destroy();
    void Update();
    void Load(const std::string& entitySettingsFile); // Add a Load method for loading entity-specific data

    void AddComponent(Component* component);
    void RemoveComponent(Component* component);
    const std::string& GetName() const;

private:
    std::string name; // Member variable to store the name of the entity
};
