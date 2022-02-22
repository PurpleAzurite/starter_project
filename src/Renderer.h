#pragma once

#include "Logging.h"
#include <cassert>
#include <glad/glad.h>

#define GLCALL(x)                                                                                 \
    openGlClearErrors();                                                                           \
    x;                                                                                             \
    assert(openGlLogErrors(#x, __LINE__, __FILE__))

static void openGlClearErrors()
{
    while (glGetError() != GL_NO_ERROR)
        ;
}

static bool openGlLogErrors(const char* fn, int line, const char* file)
{
    while (auto error = glGetError())
    {
        ENGINE_ERROR("[OPENGL] Function {} | line {} of file {}", fn, line, file);
        return false;
    }

    return true;
}
