#pragma once
#include <string>
#include <list>

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
};
