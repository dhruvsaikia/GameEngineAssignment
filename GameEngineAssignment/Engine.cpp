#include "Engine.h"
#include "RenderSystem.h"
#include "InputManager.h"
#include "AssetManager.h"
#include "SceneManager.h"
#include "Component.h"
#include "Entity.h"
#include "Object.h"
#include "Scene.h"
#include <iostream>

Engine::Engine() : renderSystem(nullptr), inputManager(nullptr), assetManager(nullptr), sceneManager(nullptr) {
    // Constructor
    std::cout << "Engine Created" << std::endl;
}

Engine::~Engine() {
    // Destructor
    Destroy(); // Make sure to call Destroy to clean up resources
    std::cout << "Engine Destroyed" << std::endl;
}

void Engine::Initialize() {
    // Load game settings and initialize systems
    Load("GameSettings.json");

    // Initialize other systems
    renderSystem = new RenderSystem();
    renderSystem->Initialize();

    // Initialize other systems in a similar manner
    inputManager = new InputManager();
    inputManager->Initialize();

    assetManager = new AssetManager();
    assetManager->Initialize();

    sceneManager = new SceneManager();
    sceneManager->Initialize();

    std::cout << "Engine Initialized" << std::endl;
}

void Engine::Destroy() {
    // Cleanup resources

    if (renderSystem) {
        delete renderSystem;
        renderSystem = nullptr;
    }

    if (inputManager) {
        delete inputManager;
        inputManager = nullptr;
    }

    if (assetManager) {
        delete assetManager;
        assetManager = nullptr;
    }

    if (sceneManager) {
        delete sceneManager;
        sceneManager = nullptr;
    }

    std::cout << "Engine Destroyed" << std::endl;
}

void Engine::GameLoop() {
    for (int i = 0; i < 5; i++) {
        // Game loop logic
        renderSystem->Update();
        // Call Update on other systems, scenes, entities, etc.
    }
}

void Engine::Load(const std::string& settingsFile) {
    // Load game settings from the provided JSON file (e.g., "GameSettings.json")
    // Parse the JSON data and extract necessary information
    // For example, you can use a JSON library like "nlohmann/json" for this
    std::cout << "Loading game settings from: " << settingsFile << std::endl;
}
