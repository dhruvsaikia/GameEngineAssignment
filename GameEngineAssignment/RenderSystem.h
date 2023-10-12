#pragma once

#include <string>

class RenderSystem {
public:
    RenderSystem();
    ~RenderSystem();

    void Initialize();
    void Destroy();
    void Update();
    void Load(const std::string& renderSettingsFile);

private:
    std::string name;
    int width;
    int height;
    bool fullscreen;
};
