#ifndef JERBOA_JERBOA_H
#define JERBOA_JERBOA_H

#include <cstdint>

namespace Jerboa
{
    template<class T>
    class ComponentID
    {
    private:
        std::size_t _index;

        ComponentID(std::size_t index)
            : _index(index)
        {}
    };
} // Jerboa

#endif // JERBOA_JERBOA_H
