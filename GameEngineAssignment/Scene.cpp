#include "Scene.h"
#include "Entity.h"
#include "json.hpp"
#include <iostream>
#include <fstream>

Scene::Scene(const std::string& name) : name(name) {
    std::cout << "Scene '" << name << "' Created" << std::endl; 
}

Scene::~Scene() {
    std::cout << "Scene '" << name << "' Destructor" << std::endl; 
}

void Scene::Initialize() {
    std::cout << "Scene '" << name << "' Initialize" << std::endl;
    for (Entity* entity : entities) {
        entity->Initialize();
    }
}

void Scene::Destroy() {
    for (Entity* entity : entities) {
        entity->Destroy();
        delete entity;
    }
    entities.clear();
    std::cout << "Scene Destroyed" << std::endl;
}

void Scene::Update() {
    for (Entity* entity : entities) {
        entity->Update();
    }
}

void Scene::Load(const json::JSON& sceneData) {
    std::cout << "Scene Load" << std::endl;

    if (sceneData.hasKey("Entities")) {
        auto& entitiesData = const_cast<json::JSON&>(sceneData)["Entities"];
        for (auto& entityData : entitiesData.ArrayRange()) {
            if (entityData.hasKey("name")) {
                std::string entityName = entityData["name"].ToString();
                Entity* newEntity = new Entity(entityName);
                newEntity->Load(entityData);
                entities.push_back(newEntity);
            }
        }
    }
}

void Scene::AddEntity(Entity* entity) {
    entities.push_back(entity);
}

void Scene::RemoveEntity(Entity* entity) {
    entities.remove(entity);
    delete entity;
}
