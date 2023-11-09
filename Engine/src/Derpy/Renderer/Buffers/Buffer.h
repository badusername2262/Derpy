#pragma once

#include "../../Core.h"

namespace DERPY
{
    class DERPY_API OpenGLBuffer
    {
    public:
        OpenGLBuffer(float* data, int count);
        
        void Bind();
        void unBind();
    private:
        unsigned int pBufferID;
    };
}