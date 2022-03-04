////////////////////////////////////////////////////////////
//
// SFML - Simple and Fast Multimedia Library
// Copyright (C) 2007 Laurent Gomila (laurent.gom@gmail.com)
//
// This software is provided 'as-is', without any express or implied warranty.
// In no event will the authors be held liable for any damages arising from the use of this software.
//
// Permission is granted to anyone to use this software for any purpose,
// including commercial applications, and to alter it and redistribute it freely,
// subject to the following restrictions:
//
// 1. The origin of this software must not be misrepresented;
//    you must not claim that you wrote the original software.
//    If you use this software in a product, an acknowledgment
//    in the product documentation would be appreciated but is not required.
//
// 2. Altered source versions must be plainly marked as such,
//    and must not be misrepresented as being the original software.
//
// 3. This notice may not be removed or altered from any source distribution.
//
////////////////////////////////////////////////////////////

#ifndef SFML_EVENT_HPP
#define SFML_EVENT_HPP

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <SFML/Config.hpp>


namespace sf
{
////////////////////////////////////////////////////////////
/// Definition of key codes for keyboard events
////////////////////////////////////////////////////////////
struct Key
{
    enum Code
    {
        A = 'a', Z = 'z', E = 'e', R = 'r', T = 't', Y = 'y', U = 'u', I = 'i', O = 'o', P = 'p',
        Q = 'q', S = 's', D = 'd', F = 'f', G = 'g', H = 'h', J = 'j', K = 'k', L = 'l', M = 'm',
        W = 'w', X = 'x', C = 'c', V = 'v', B = 'b', N = 'n',
        Num0 = '0', Num1 = '1', Num2 = '2', Num3 = '3', Num4 = '4',
        Num5 = '5', Num6 = '6', Num7 = '7', Num8 = '8', Num9 = '9', 
        Escape = 256,
        Space, Return, Back, Tab, PageUp, PageDown, End, Home, Insert, Delete, Add, Subtract, Multiply, Divide,
        Left, Right, Up, Down,
        Numpad0, Numpad1, Numpad2, Numpad3, Numpad4, Numpad5, Numpad6, Numpad7, Numpad8, Numpad9,
        F1, F2, F3, F4, F5, F6, F7, F8, F9, F10, F11, F12, F13, F14, F15,
        Pause,

        Count // For internal use
    };
};


////////////////////////////////////////////////////////////
/// Definition of button codes for mouse events
////////////////////////////////////////////////////////////
struct Mouse
{
    enum Button
    {
        Left   = 1 << 1,
        Right  = 1 << 2,
        Middle = 1 << 3
    };
};


////////////////////////////////////////////////////////////
/// Event defines a system event and its parameters
////////////////////////////////////////////////////////////
class Event
{
public :

    ////////////////////////////////////////////////////////////
    /// Enumeration of the different types of events
    ////////////////////////////////////////////////////////////
    enum EventType
    {
        Close,
        Resize,
        LostFocus,
        GainedFocus,
        TextEntered,
        KeyPressed,
        KeyReleased,
        MouseWheelMoved,
        MouseButtonPressed,
        MouseButtonReleased,
        MouseMove,
        JoystickButtonPressed,
        JoystickButtonReleased,
        JoystickMove
    };

    ////////////////////////////////////////////////////////////
    // Member data
    ////////////////////////////////////////////////////////////
    EventType Type; ///< Type of the event

    union
    {

        ////////////////////////////////////////////////////////////
        /// Text event parameters
        ////////////////////////////////////////////////////////////
        struct
        {
            Uint16 Unicode;
        } Text;

        ////////////////////////////////////////////////////////////
        /// Keyboard events parameters
        ////////////////////////////////////////////////////////////
        struct
        {
            Key::Code Code;
            bool      Alt;
            bool      Control;
            bool      Shift;
        } Key;

        ////////////////////////////////////////////////////////////
        /// Mouse events parameters
        ////////////////////////////////////////////////////////////
        struct
        {
            unsigned int Buttons;
            unsigned int X;
            unsigned int Y;
        } Mouse;

        ////////////////////////////////////////////////////////////
        /// Mouse wheel events parameters
        ////////////////////////////////////////////////////////////
        struct
        {
            int Delta;
        } MouseWheel;

        ////////////////////////////////////////////////////////////
        /// Joystick events parameters
        ////////////////////////////////////////////////////////////
        struct
        {
            unsigned int JoystickId;
            unsigned int Button;
            int          X;
            int          Y;
            int          Z;
        } Joystick;

        ////////////////////////////////////////////////////////////
        /// Size events parameters
        ////////////////////////////////////////////////////////////
        struct
        {
            unsigned int Width;
            unsigned int Height;
        } Size;
    };
};

} // namespace sf


#endif // SFML_EVENT_HPP
