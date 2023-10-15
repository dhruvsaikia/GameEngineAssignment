#include "Engine.h"
#include "RenderSystem.h"
#include "InputManager.h"
#include "AssetManager.h"
#include "SceneManager.h"
#include "Scene.h"
#include <iostream>
#include <fstream>
#include "json.hpp"

Engine::Engine() {
    std::cout << "Engine Create" << std::endl;  

    inputManager = new InputManager();
    std::cout << "InputManager Create" << std::endl;  
    assetManager = new AssetManager();
    std::cout << "AssetManager Create" << std::endl;  
    sceneManager = new SceneManager();
    std::cout << "SceneManager Create" << std::endl;  
    renderSystem = new RenderSystem();
    std::cout << "RenderSystem Create" << std::endl;  
}

Engine::~Engine() {
    std::cout << "Engine Destructor" << std::endl;
}

void Engine::Initialize() {
    std::cout << "Engine Initialize" << std::endl;
    Load("GameSettings.json");
    std::cout << "Engine Loaded" << std::endl;

    inputManager->Load();
    assetManager->Load();
    sceneManager->Load(jsonData);
    renderSystem->Initialize(jsonData);  

    for (auto& sceneData : jsonData["SceneManager"].ArrayRange()) {
        for (auto& scene : sceneManager->GetScenes()) {
            scene->Load(sceneData);
            scene->Initialize();  
        }
    }

    inputManager->Initialize(); 
    assetManager->Initialize();  
    sceneManager->Initialize();  


}

void Engine::Destroy() {
    std::cout << "Engine Destroy" << std::endl;

    if (sceneManager) {
        sceneManager->Destroy();
        delete sceneManager;
        sceneManager = nullptr;
    }

    if (assetManager) {
        assetManager->Destroy();
        delete assetManager;
        assetManager = nullptr;
    }

    if (inputManager) {
        inputManager->Destroy();
        delete inputManager;
        inputManager = nullptr;
    }

    if (renderSystem) {
        renderSystem->Destroy();
        delete renderSystem;
        renderSystem = nullptr;
    }
}

void Engine::GameLoop() {
    for (int i = 0; i < 5; i++) {
        std::cout << "======== Engine Loop " << i + 1 << " Start ========" << std::endl;  

        std::cout << "Engine Loop Update" << std::endl; 
        inputManager->Update();
        assetManager->Update();
        sceneManager->Update();
        renderSystem->Update();

    }
    std::cout << "\nBegin Deletion" << std::endl; 
}

void Engine::Load(const std::string& settingsFile) {
    std::ifstream inFile(settingsFile);
    if (!inFile.is_open()) {
        std::cerr << "Error: Unable to open settings file: " << settingsFile << std::endl;
        return;
    }

    std::string content((std::istreambuf_iterator<char>(inFile)), std::istreambuf_iterator<char>());

    jsonData = json::JSON::Load(content);

    if (jsonData.hasKey("SceneManager")) {
        for (auto& sceneData : jsonData["SceneManager"].ArrayRange()) {
            Scene* scene = new Scene(sceneData["name"].ToString());
            scene->Load(sceneData);  
            sceneManager->AddScene(scene);
        }
    }
}