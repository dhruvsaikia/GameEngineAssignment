#include "SceneManager.h"
#include "Scene.h" 
#include <iostream> 

SceneManager::SceneManager() {
    std::cout << "SceneManager Created" << std::endl;
}

SceneManager::~SceneManager() {
    Destroy();
    std::cout << "SceneManager Destroyed" << std::endl;
}

void SceneManager::Initialize() {
    std::cout << "SceneManager Initialized" << std::endl;
}

void SceneManager::Destroy() {
    std::cout << "SceneManager Destroyed" << std::endl;
}

void SceneManager::Update() {
}

void SceneManager::AddScene(Scene* scene) {
}

void SceneManager::RemoveScene(Scene* scene) {
}
