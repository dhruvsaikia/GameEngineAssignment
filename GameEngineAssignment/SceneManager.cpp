#include "SceneManager.h"
#include "Scene.h"
#include "json.hpp"
#include <iostream>

SceneManager::SceneManager() {
    std::cout << "SceneManager Created" << std::endl;
}

SceneManager::~SceneManager() {
    Destroy();
    std::cout << "SceneManager Destructor" << std::endl;
}

void SceneManager::Initialize() {
    std::cout << "SceneManager Initialized" << std::endl;
    for (auto& scene : scenes) {
        scene->Initialize();
    }
}

void SceneManager::Destroy() {
    for (auto& scene : scenes) {
        scene->Destroy();
        delete scene;
    }
    scenes.clear();
    std::cout << "SceneManager Destroyed" << std::endl;
}

void SceneManager::Update() {
    for (auto& scene : scenes) {
        scene->Update();
    }
}

void SceneManager::AddScene(Scene* scene) {
    scenes.push_back(scene);
}

void SceneManager::RemoveScene(Scene* scene) {
    scenes.remove(scene);
    scene->Destroy();
    delete scene;
}

void SceneManager::LoadScenes(json::JSON& document) {
    if (document.hasKey("SceneManager")) {
        json::JSON sceneSettings = document["SceneManager"];

        for (auto& sceneData : sceneSettings.ArrayRange()) {
            if (sceneData.hasKey("SceneFile")) {
                Scene* newScene = new Scene();
                newScene->Load(sceneData["SceneFile"].ToString());
                scenes.push_back(newScene);
            }
        }
    }
}