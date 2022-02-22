#pragma once

#include "Layer.h"

namespace Engine {

class ImGuiLayer : public Layer
{
public:
    void onAttach() override;
    void runImGui();
    void onUpdate() override;
    void endImGui();
    void onDetach() override;
};

} // namespace Engine