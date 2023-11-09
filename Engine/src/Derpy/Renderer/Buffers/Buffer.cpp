#include "../../../Pch.h"
#include "Buffer.h"

#include <glad/gl.h>

namespace DERPY
{
    OpenGLBuffer::OpenGLBuffer(float* data, int count)
    {
        glGenBuffers(1, &pBufferID);
        glBindBuffer(GL_ARRAY_BUFFER, pBufferID);
        glBufferData(GL_ARRAY_BUFFER, count * sizeof(float), data, GL_STATIC_DRAW);
        glBindBuffer(GL_ARRAY_BUFFER, 0);
    }

    void OpenGLBuffer::Bind()
    {
        glBindBuffer(GL_ARRAY_BUFFER, pBufferID);
    }

    void OpenGLBuffer::unBind()
    {
        glBindBuffer(GL_ARRAY_BUFFER, 0);
    }
}