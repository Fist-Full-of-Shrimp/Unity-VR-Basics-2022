#pragma once

#include <cassert>
#include <deque>
#include <mutex>
#include <stdlib.h>
#include <string>
#include <thread>

enum Command
{
    kStartFunctionCall,
    kStartStruct,

    kFloat,
    kString,
    kInt32,
    kInt64,
    kUInt32,
    kUInt64,

    kEndStruct,
    kEndFunctionCall,

    kCacheNotLargeEnough,

    kEndData = 0xFFFFFFFF
};

#include "ringbuf.h"

static std::mutex s_DataMutex;

// Accessing this must be protected with s_DataMutex.
// Only add into these at kEndFunctionCall to avoid mixing with other threads.
static RingBuf s_MainDataStore = {};

// Thread local storage of serialized commands.
// On EndFunctionCall they'll be moved into the static storage w/ mutex lock.
thread_local RingBuf s_ThreadLocalDataStore = {};

// These get set from c# in HookXrInstanceProcAddr
static uint32_t s_CacheSize = 0;
static uint32_t s_PerThreadCacheSize = 0;

static void StartFunctionCall(const char* funcName)
{
    if (s_ThreadLocalDataStore.cacheSize != s_PerThreadCacheSize)
    {
        s_ThreadLocalDataStore.Destroy();
        s_ThreadLocalDataStore.Create(s_PerThreadCacheSize);
    }

    s_ThreadLocalDataStore.CreateNewBlock();
    s_ThreadLocalDataStore.Write(kStartFunctionCall);
    s_ThreadLocalDataStore.Write(std::this_thread::get_id());
    s_ThreadLocalDataStore.Write(funcName);
}

static void StartStruct(const char* fieldName, const char* structName)
{
    s_ThreadLocalDataStore.Write(kStartStruct);
    s_ThreadLocalDataStore.Write(fieldName);
    s_ThreadLocalDataStore.Write(structName);
}

static void SendFloat(const char* fieldName, float t)
{
    s_ThreadLocalDataStore.Write(kFloat);
    s_ThreadLocalDataStore.Write(fieldName);
    s_ThreadLocalDataStore.Write(t);
}

static void SendString(const char* fieldName, const char* t)
{
    s_ThreadLocalDataStore.Write(kString);
    s_ThreadLocalDataStore.Write(fieldName);
    s_ThreadLocalDataStore.Write(t);
}

static void SendInt32(const char* fieldName, int32_t t)
{
    s_ThreadLocalDataStore.Write(kInt32);
    s_ThreadLocalDataStore.Write(fieldName);
    s_ThreadLocalDataStore.Write(t);
}

static void SendInt64(const char* fieldName, int64_t t)
{
    s_ThreadLocalDataStore.Write(kInt64);
    s_ThreadLocalDataStore.Write(fieldName);
    s_ThreadLocalDataStore.Write(t);
}

static void SendUInt32(const char* fieldName, uint32_t t)
{
    s_ThreadLocalDataStore.Write(kUInt32);
    s_ThreadLocalDataStore.Write(fieldName);
    s_ThreadLocalDataStore.Write(t);
}

static void SendUInt64(const char* fieldName, uint64_t t)
{
    s_ThreadLocalDataStore.Write(kUInt64);
    s_ThreadLocalDataStore.Write(fieldName);
    s_ThreadLocalDataStore.Write(t);
}

static void EndStruct()
{
    s_ThreadLocalDataStore.Write(kEndStruct);
}

static void EndFunctionCall(const char* funcName, const char* result)
{
    s_ThreadLocalDataStore.Write(kEndFunctionCall);
    s_ThreadLocalDataStore.Write(result);

    {
        std::lock_guard<std::mutex> guard(s_DataMutex);

        if (s_MainDataStore.cacheSize != s_CacheSize)
        {
            s_MainDataStore.Destroy();
            s_MainDataStore.Create(s_CacheSize);
        }

        if (s_ThreadLocalDataStore.HasDataForRead())
        {
            s_MainDataStore.CreateNewBlock();
            uint8_t* ptr{};
            uint32_t size{};
            bool more = false;
            do
            {
                more = s_ThreadLocalDataStore.GetForRead(&ptr, &size);
                uint8_t* dst = s_MainDataStore.GetForWrite(size);
                memcpy(dst, ptr, size);
            } while (more);
        }
        else
        {
            s_MainDataStore.CreateNewBlock();
            s_MainDataStore.Write(kCacheNotLargeEnough);
            s_MainDataStore.Write(std::this_thread::get_id());
            s_MainDataStore.Write(funcName);
            s_MainDataStore.Write(result);
        }
    }
}
