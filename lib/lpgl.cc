#include "GL/lpgl.h"

#include <cstdio>
#include <cstring>

namespace lpgl
{
    static class _LpglContext
    {
    public:
        int width, height, nChannel = 3;
        uint8_t* frameBuffer = nullptr;
        uint32_t clearColor = 0x00000000;

        ~_LpglContext();
        void init(int width, int height);
    } _lpglContext;

    void _LpglContext::init(int width, int height)
    {
        frameBuffer = new uint8_t[width * 2 * height * 2 * nChannel];
    }

    _LpglContext::~_LpglContext()
    {
        if (frameBuffer) {
            delete[] frameBuffer;
            frameBuffer = nullptr;
        }
    }

    void lpglInit(int width, int height)
    {
        _lpglContext.init(width, height);
    }

    void* lpglCommit()
    {
        return _lpglContext.frameBuffer;
    }

    extern "C" void _lpglClear(GLbitfield mask)
    {
        memset(_lpglContext.frameBuffer,
            _lpglContext.clearColor,
            sizeof(_lpglContext.width * 2 * _lpglContext.height * 2 * _lpglContext.nChannel));
    }

    extern "C" void _lpglClearColor(GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha)
    {
        _lpglContext.clearColor = GLubyte(blue * 255)
                                    | (GLubyte(green * 255) << 8)
                                    | (GLubyte(red * 255) << 16);
    }
}
