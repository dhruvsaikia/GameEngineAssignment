#pragma once

#include <list>
#include <string>

class Entity;

class Scene {
public:
    Scene();
    ~Scene();

    void Initialize();
    void Destroy();
    void Update();
    void Load(const std::string& sceneSettingsFile);

    void AddEntity(Entity* entity);
    void RemoveEntity(Entity* entity);

private:
    std::string name;
    std::list<Entity*> entities; 
};
