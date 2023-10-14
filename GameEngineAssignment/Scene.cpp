#include "Scene.h"
#include "Entity.h"
#include "json.hpp"
#include <iostream>
#include <fstream>

Scene::Scene() {
    std::cout << "Scene Created" << std::endl;
}

Scene::~Scene() {
    Destroy();
    std::cout << "Scene Destructor" << std::endl;
}

void Scene::Initialize() {
    for (Entity* entity : entities) {
        entity->Initialize();
    }
    std::cout << "Scene Initialized" << std::endl;
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

void Scene::Load(const std::string& sceneSettingsFile) {
    std::cout << "Loading scene settings from: " << sceneSettingsFile << std::endl;

    std::ifstream inputFile(sceneSettingsFile);
    if (!inputFile.is_open()) {
        std::cerr << "Failed to open " << sceneSettingsFile << std::endl;
        return;
    }

    std::string fileContent(
        (std::istreambuf_iterator<char>(inputFile)),
        std::istreambuf_iterator<char>()
    );

    json::JSON document = json::JSON::Load(fileContent);
    if (document.hasKey("Entities")) {
        for (auto& entityData : document["Entities"].ArrayRange()) {
            Entity* newEntity = new Entity(entityData["Name"].ToString());
            entities.push_back(newEntity);
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
