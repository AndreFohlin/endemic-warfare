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

#ifndef SFML_INPUT_HPP
#define SFML_INPUT_HPP

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <SFML/Config.hpp>
#include <SFML/System/NonCopyable.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/WindowListener.hpp>


namespace sf
{
////////////////////////////////////////////////////////////
/// Input handles real-time input from keyboard and mouse.
/// Use it instead of events to handle continuous moves and more
/// game-friendly inputs
////////////////////////////////////////////////////////////
class SFML_API Input : public WindowListener, NonCopyable
{
public :

    ////////////////////////////////////////////////////////////
    /// Default constructor
    ///
    ////////////////////////////////////////////////////////////
    Input();

    ////////////////////////////////////////////////////////////
    /// Get the state of a key
    ///
    /// \param KeyCode : Key to check
    ///
    /// \return True if key is down, false if key is up
    ///
    ////////////////////////////////////////////////////////////
    bool IsKeyDown(Key::Code KeyCode) const;

    ////////////////////////////////////////////////////////////
    /// Get the state of a mouse button
    ///
    /// \param Button : Button to check
    ///
    /// \return True if button is down, false if button is up
    ///
    ////////////////////////////////////////////////////////////
    bool IsMouseButtonDown(Mouse::Button Button) const;

    ////////////////////////////////////////////////////////////
    /// Get the state of a joystick button
    ///
    /// \param JoyId :  Identifier of the joystick to check (0 or 1)
    /// \param Button : Button to check
    ///
    /// \return True if button is down, false if button is up
    ///
    ////////////////////////////////////////////////////////////
    bool IsJoystickButtonDown(unsigned int JoyId, unsigned int Button) const;

    ////////////////////////////////////////////////////////////
    /// Get the mouse X position
    ///
    /// \return Current mouse left position, relative to owner window
    ///
    ////////////////////////////////////////////////////////////
    unsigned int GetMouseX() const;

    ////////////////////////////////////////////////////////////
    /// Get the mouse Y position
    ///
    /// \return Current mouse top position, relative to owner window
    ///
    ////////////////////////////////////////////////////////////
    unsigned int GetMouseY() const;

    ////////////////////////////////////////////////////////////
    /// Get the joystick X position
    ///
    /// \param JoyId : Identifier of the joystick to check (0 or 1)
    ///
    /// \return Current joystick X position, in the range [-100, 100]
    ///
    ////////////////////////////////////////////////////////////
    int GetJoystickX(unsigned int JoyId) const;

    ////////////////////////////////////////////////////////////
    /// Get the joystick Y position
    ///
    /// \param JoyId : Identifier of the joystick to check (0 or 1)
    ///
    /// \return Current joystick Y position, in the range [-100, 100]
    ///
    ////////////////////////////////////////////////////////////
    int GetJoystickY(unsigned int JoyId) const;

    ////////////////////////////////////////////////////////////
    /// Get the joystick Z position
    ///
    /// \param JoyId : Identifier of the joystick to check (0 or 1)
    ///
    /// \return Current joystick Z position, in the range [-100, 100]
    ///
    ////////////////////////////////////////////////////////////
    int GetJoystickZ(unsigned int JoyId) const;

private :

    ////////////////////////////////////////////////////////////
    /// /see sfWindowListener::OnEvent
    ///
    ////////////////////////////////////////////////////////////
    virtual void OnEvent(const Event& EventReceived);

    ////////////////////////////////////////////////////////////
    // Member data
    ////////////////////////////////////////////////////////////
    bool          myKeys[Key::Count];      ///< Array containing the state of all keayboard keys
    bool          myMouseButtons[3];       ///< Array containing the state of all mouse buttons
    bool          myJoystickButtons[2][8]; ///< Array containing the state of all joysticks buttons
    unsigned int  myMouseX;                ///< Mouse position on X
    unsigned int  myMouseY;                ///< Mouse position on Y
    int           myJoystickX[2];          ///< Joysticks position on X
    int           myJoystickY[2];          ///< Joysticks position on Y
    int           myJoystickZ[2];          ///< Joysticks position on Z
};

} // namespace sf


#endif // SFML_INPUT_HPP
