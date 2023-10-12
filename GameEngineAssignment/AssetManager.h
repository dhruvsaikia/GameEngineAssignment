#pragma once

#include <string>

class AssetManager {
public:
    AssetManager();
    ~AssetManager();

    void Initialize();
    void Destroy();
    void Update();
    void Load(const std::string& assetSettingsFile);
};
