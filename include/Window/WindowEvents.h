#pragma once
#include "WindowInputs.h"

// AppWindow Events
struct WindowMaximizeEvent {};

struct WindowIconifyEvent {};

struct WindowRestoreEvent {};

struct WindowCloseEvent {};

struct WindowResizeEvent
{
    inline WindowResizeEvent(int32_t w, int32_t h):
	Width(w), Height(h)
	{}

    int32_t Height = 0;
    int32_t Width = 0;
};

// Key events
struct KeyReleaseEvent
{
    inline KeyReleaseEvent(int32_t key):
	Key(key)
	{}

    int32_t Key = -1;
};

struct KeyPressEvent
{
    inline KeyPressEvent(int32_t key):
	Key(key)
	{}
    int32_t Key = -1;
};

struct KeyRepeatEvent
{
    inline KeyRepeatEvent(int32_t key):
	Key(key)
	{}
    int32_t Key = -1;
};

// Mouse Events
struct MouseReleaseEvent
{
    inline MouseReleaseEvent(int32_t b):
	Button(b)
	{}
    int32_t Button = -1;
};

struct MouseDownEvent
{
    inline MouseDownEvent(int32_t b):
	Button(b)
	{}
    int32_t Button = -1;
};

struct MouseDragEvent
{
    inline MouseDragEvent(double dx, double dy):
	DeltaX(dx), DeltaY(dy)
	{}
    double DeltaX = 0.0, DeltaY = 0.0;
};

struct MouseMotionEvent
{
    inline MouseMotionEvent(double x, double y):
	TargetX(x), TargetY(y)
	{}
    double TargetX = 0.0, TargetY = 0.0;
};

struct MouseWheelEvent
{
    inline MouseWheelEvent(double sx, double sy):
	ScrollX(sx), ScrollY(sy)
	{}
    double ScrollX = 0.0, ScrollY = 0.0;
};

    
