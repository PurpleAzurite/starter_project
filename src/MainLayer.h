#pragma once

#include "Layer.h"
#include <imgui.h>

namespace Engine {

class MainLayer : public Layer
{
public:
    void onAttach() override;
    void onUpdate() override;
    void onDetach() override;

private:
    ImVec4 m_clearColor {0.1, 0.2, 0.3, 1.0};

};

} // namespace Engine
