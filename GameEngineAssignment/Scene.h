#pragma once

#include <list>
#include <string>
#include "Entity.h" 
#include "json.hpp"  

class Scene {
public:
    Scene(const std::string& name);  
    ~Scene();

    void Initialize();
    void Destroy();
    void Update();
    void Load(const json::JSON& sceneData);

    void AddEntity(Entity* entity);
    void RemoveEntity(Entity* entity);

private:
    std::string name;
    std::list<Entity*> entities;
};