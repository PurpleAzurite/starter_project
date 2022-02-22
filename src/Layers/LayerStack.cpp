// clang-format off
#include "LayerStack.h"
#include <algorithm>
// clang-format on

namespace Engine {

LayerStack::LayerStack()
    : m_insertionItr(m_layers.begin())
{
}

LayerStack::~LayerStack()
{
    for (auto* l : m_layers)
        l->onDetach();
}

void LayerStack::pushLayer(Layer* layer)
{
    m_insertionItr = m_layers.emplace(m_insertionItr, layer);
}

void LayerStack::popLayer(Layer* layer)
{
    if (auto itr = std::find(m_layers.begin(), m_layers.end(), layer); itr != m_layers.end())
    {
        layer->onDetach();
        m_layers.erase(itr);
        --m_insertionItr;
    }
}

void LayerStack::pushOverlay(Layer* overlay) { m_layers.emplace_back(overlay); }

void LayerStack::popOverlay(Layer* overlay)
{
    if (auto itr = std::find(m_layers.begin(), m_layers.end(), overlay); itr != m_layers.end())
    {
        overlay->onDetach();
        m_layers.erase(itr);
    }
}

} // namespace Engine
