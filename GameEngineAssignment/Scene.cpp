#include "Scene.h"
#include "Entity.h" 
#include <iostream>

Scene::Scene() {
    std::cout << "Scene Created" << std::endl;
}

Scene::~Scene() {
    Destroy();
    std::cout << "Scene Destroyed" << std::endl;
}

void Scene::Initialize() {
    std::cout << "Scene Initialized" << std::endl;
}

void Scene::Destroy() {
    std::cout << "Scene Destroyed" << std::endl;
}

void Scene::Update() {
}

void Scene::Load(const std::string& sceneSettingsFile) {
    std::cout << "Loading scene settings from: " << sceneSettingsFile << std::endl;
}

void Scene::AddEntity(Entity* entity) {
}

void Scene::RemoveEntity(Entity* entity) {
}
