#pragma once

class Object {
public:
    Object();
    ~Object();

    void Initialize();
    void Destroy();
    bool IsInitialized() const;
};
