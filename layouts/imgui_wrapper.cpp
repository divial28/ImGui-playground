#if defined(_MSC_VER)
#pragma warning(push)
#pragma warning(disable : 4099) // type name first seen using 'class' now seen using 'struct'
#pragma warning(disable : 4244) // 'argument': conversion from 'float' to 'int', possible loss of data
#pragma warning(disable : 4267) // conversion from 'size_t' to 'int', possible loss of data
#pragma warning(disable : 4305) // 'argument': truncation from 'double' to 'float'
#endif // _MSC_VER

#if defined(__clang__)
#pragma clang diagnostic ignored "-Wtautological-constant-out-of-range-compare"
#endif // __clang__

#if (defined(WIN32) || defined(_WIN32) || defined(__WIN32)) && !defined(__CYGWIN__)
#define NOMINMAX
#define WIN32_LEAN_AND_MEAN
#endif


#include "imgui.cpp"
#include "imgui_demo.cpp"
#include "imgui_draw.cpp"
#include "imgui_tables.cpp"
#include "imgui_widgets.cpp"
#include "misc/cpp/imgui_stdlib.cpp"
#include "backends/imgui_impl_opengl3.cpp"
#include "backends/imgui_impl_glfw.cpp"


#if defined(_MSC_VER)
#pragma warning(pop)
#endif // _MSC_VER
