#include "Engine.h"
#include "RenderSystem.h"
#include "InputManager.h"
#include "AssetManager.h"
#include "SceneManager.h"
#include "Scene.h"
#include <iostream>
#include <fstream>
#include "json.hpp"

Engine::Engine() : renderSystem(nullptr), inputManager(nullptr), assetManager(nullptr), sceneManager(nullptr) {
    std::cout << "Engine Created" << std::endl;
}

Engine::~Engine() {
    Destroy();
    std::cout << "Engine Destructor" << std::endl;
}

void Engine::Initialize() {
    std::cout << "Engine Initialize" << std::endl;
    Load("GameSettings.json");

    renderSystem = new RenderSystem();
    renderSystem->Initialize(jsonData);

    inputManager = new InputManager();
    inputManager->Initialize();

    assetManager = new AssetManager();
    assetManager->Initialize();

    sceneManager = new SceneManager();
    sceneManager->Initialize();

    // Load game level from JSON file
    sceneManager->LoadScenes(jsonData); 

    std::cout << "Engine Initialized" << std::endl;
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
        std::cout << "======== Engine Cycle " << i + 1 << " Commence ========" << std::endl;

        std::cout << "Engine Cycle Update" << std::endl;
        renderSystem->Update();
        inputManager->Update();
        assetManager->Update();
        sceneManager->Update();

        std::cout << "======== Engine Cycle " << i + 1 << " Complete ========" << std::endl;
    }
    std::cout << "\n## Start Cleanup" << std::endl;
}

void Engine::Load(const std::string& settingsFile) {
    std::cout << "Engine Load" << std::endl;
    std::cout << "Loading game settings from: " << settingsFile << std::endl;

    std::ifstream inFile(settingsFile);
    if (!inFile.is_open()) {
        std::cerr << "Error: Unable to open settings file: " << settingsFile << std::endl;
        return;
    }

    std::string content((std::istreambuf_iterator<char>(inFile)), std::istreambuf_iterator<char>());

    jsonData = json::JSON::Load(content);
    std::cout << "Engine Loaded" << std::endl;
}
