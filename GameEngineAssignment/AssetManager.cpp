#include "AssetManager.h"
#include <iostream>

AssetManager::AssetManager() {
    std::cout << "AssetManager Created" << std::endl;
}

AssetManager::~AssetManager() {
    Destroy();
    std::cout << "AssetManager Destroyed" << std::endl;
}

void AssetManager::Initialize() {
    Load("AssetSettings.json");
    std::cout << "AssetManager Initialized" << std::endl;
}

void AssetManager::Destroy() {
    std::cout << "AssetManager Destroyed" << std::endl;
}

void AssetManager::Update() {
}

void AssetManager::Load(const std::string& assetSettingsFile) {
    std::cout << "Loading asset settings from: " << assetSettingsFile << std::endl;
}
