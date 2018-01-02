#ifndef LPGL_H_
#define LPGL_H_

#include <cstdint>

typedef uint32_t GLbitfield;
typedef float GLclampf;
typedef uint8_t GLubyte;

namespace lpgl
{
    void lpglInit(int width, int height);
    void* lpglCommit();

    extern "C" void _lpglClear(GLbitfield mask);
    extern "C" void _lpglClearColor(GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha);
}

#ifdef glClear
#undef glClear
#endif // glClear
#define glClear(mask) _lpglClear(mask)

#ifdef glClearColor
#undef glClearColor
#endif // glClearColor
#define glClearColor(red, blue, green, alpha) _lpglClearColor(red, blue, green, alpha)

#endif // LPGL_H_