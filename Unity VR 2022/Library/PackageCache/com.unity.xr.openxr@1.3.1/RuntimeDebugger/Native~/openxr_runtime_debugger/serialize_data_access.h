#pragma once

#include <sstream>

extern "C" void UNITY_INTERFACE_EXPORT StartDataAccess()
{
    s_DataMutex.lock();
}

extern "C" bool UNITY_INTERFACE_EXPORT GetDataForRead(uint8_t** ptr, uint32_t* size)
{
    return s_MainDataStore.GetForRead(ptr, size);
}

extern "C" void UNITY_INTERFACE_EXPORT EndDataAccess()
{
    s_MainDataStore.Reset();
    s_DataMutex.unlock();
}