#include "AssetManager.h"
#include <iostream>

AssetManager::AssetManager() {
    std::cout << "AssetManager Create" << std::endl;
}

AssetManager::~AssetManager() {
    Destroy();
    std::cout << "AssetManager Destructor" << std::endl;
}

void AssetManager::Initialize() {
    std::cout << "AssetManager Initialize" << std::endl;
}

void AssetManager::Destroy() {
    std::cout << "AssetManager Destroy" << std::endl;
}

void AssetManager::Update() {
    std::cout << "AssetManager Update" << std::endl;
}

void AssetManager::Load() {
    std::cout << "AssetManager Load" << std::endl;
}
