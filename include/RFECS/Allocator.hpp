#ifndef RFECS_ALLOCATOR_HPP
#define RFECS_ALLOCATOR_HPP
#if _MSC_VER > 1000
#pragma once
#endif

namespace RadonFastEntityComponentSystem {

struct Allocator
{
    virtual void* Allocate(RF_Type::Size Bytes, RF_Type::Size ByteAlignment)=0;
    virtual void Free(void* MemoryBlock)=0;
};

}

#endif // RFECS_ALLOCATOR_HPP