#pragma once

// clang-format off
#include "Layer.h"
#include <vector>
// clang-format on

namespace Engine {

class LayerStack
{
public:
    LayerStack();
    ~LayerStack();

public:
    void pushLayer(Layer* layer);
    void popLayer(Layer* layer);
    void pushOverlay(Layer* overlay);
    void popOverlay(Layer* overlay);

    inline std::vector<Layer*>::iterator begin() { return m_layers.begin(); }
    inline std::vector<Layer*>::iterator end() { return m_layers.end(); }

private:
    std::vector<Layer*> m_layers;
    std::vector<Layer*>::iterator m_insertionItr;
};

} // namespace Engine
