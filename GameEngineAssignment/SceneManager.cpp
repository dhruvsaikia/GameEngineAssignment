#include "SceneManager.h"
#include "Scene.h"
#include "json.hpp"
#include <iostream>

SceneManager::SceneManager() {
}

SceneManager::~SceneManager() {
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

void SceneManager::Load(json::JSON& jsonData) {
    std::cout << "SceneManager Load" << std::endl;
    if (jsonData.hasKey("SceneManager")) {

        for (auto& sceneData : jsonData["SceneManager"].ArrayRange()) {
            std::string sceneName = sceneData.hasKey("name") ? sceneData["name"].ToString() : "Unnamed Scene";
            Scene* newScene = new Scene(sceneName);
            if (sceneData.hasKey("SceneFile")) {
                newScene->Load(sceneData["SceneFile"].ToString());
            }
            scenes.push_back(newScene);
        }
    }
}
