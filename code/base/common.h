/* date = April 23rd 2024 7:37 pm */
#ifndef COMMON_H
#define COMMON_H

#ifndef YK_CRT
#include <stdio.h>
#define print(...) printf(__VA_ARGS__)
#endif

#include <stdint.h>

#define DEBUG 1

#define _Assert_helper(expr, format, ...)            \
do                                               \
{                                                \
if (!(expr))                                 \
{                                            \
print(format, ##__VA_ARGS__);            \
volatile int *ptr = 0;                   \
*ptr = 0;                                \
}                                            \
} while (0)

#if DEBUG
#define Assert(expr) _Assert_helper(expr, "Assert failed")
#define AssertM(expr, format, ...) _Assert_helper(expr,format,##__VA_ARGS__)
#else
#define Assert(expr)
#define AssertM(expr, format, ...)
#endif

#define INVALID_CODE_PATH() AssertM(1 > 2, "Invalid code path. Control should never reach here. Yet it did. Are you stupid? (Y or N)")

#define Kilobytes(Value) ((uint64_t)(Value) * 1024)
#define Megabytes(Value) (Kilobytes(Value) * 1024)
#define Gigabytes(Value) (Megabytes(Value) * 1024)
#define Terabytes(Value) (Gigabytes(Value) * 1024)

#define internal static
#define global static
#define local_persist static

typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;

typedef int8_t i8;
typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

typedef float f32;
typedef double f64;

typedef int32_t b32;

#define true 1
#define false 0

struct Arena
{
  size_t size;
  u8* base;
  size_t used;
};

struct ArenaTemp
{
  Arena *arena;
  size_t pos;
};

internal void* _arena_alloc(struct Arena* arena, size_t size)
{
  Assert(arena->used + size <= arena->size);
  
  void* out = arena->base + arena->used;
  arena->used += size;
  return out;
}

#define push_struct(arena, type) (type*)_arena_alloc(arena, sizeof(type))

#define push_array(arena,type,count) (type*)_arena_alloc(arena, sizeof(type) * count)
internal ArenaTemp arena_temp_begin(Arena *arena)
{
  ArenaTemp out = {0};
  out.arena = arena;
  out.pos = arena->used;
  return out;
}

internal void arena_temp_end(ArenaTemp *temp)
{
  temp->arena->used = temp->pos;
}

internal void arena_innit(struct Arena* arena, size_t size, void* base)
{
  arena->size = size;
  arena->base = (u8*)base;
  arena->used = 0;
}

#if defined _WIN32
#define YK_API __declspec(dllexport)
#else
#define YK_API
#endif

#endif //COMMON_H