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

#ifndef SFML_WINDOW_HPP
#define SFML_WINDOW_HPP

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <SFML/Config.hpp>
#include <SFML/System/NonCopyable.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Input.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <SFML/Window/WindowHandle.hpp>
#include <SFML/Window/WindowListener.hpp>
#include <SFML/System/Clock.hpp>
#include <queue>
#include <string>


namespace sf
{
namespace priv
{
    class WindowImpl;
}

////////////////////////////////////////////////////////////
/// Window is a rendering window ; it can create a new window
/// or connect to an existing one
////////////////////////////////////////////////////////////
class SFML_API Window : public WindowListener, NonCopyable
{
public :

    ////////////////////////////////////////////////////////////
    /// Enumeration of window creation styles
    ///
    ////////////////////////////////////////////////////////////
    enum Style
    {
        Resizable, ///< Resizable window
        Fixed,     ///< Fixed window (not resizable)
        Fullscreen ///< Fullscreen mode
    };

    ////////////////////////////////////////////////////////////
    /// Default constructor
    ///
    ////////////////////////////////////////////////////////////
    Window();

    ////////////////////////////////////////////////////////////
    /// Construct a new window
    ///
    /// \param Mode :              Video mode to use
    /// \param Title :             Title of the window
    /// \param WindowStyle :       Window style (resizable by default)
    /// \param AntialiasingLevel : Level of antialiasing (0 by default, disabled)
    ///
    ////////////////////////////////////////////////////////////
    Window(VideoMode Mode, const std::string& Title, Style WindowStyle = Resizable, int AntialiasingLevel = 0);

    ////////////////////////////////////////////////////////////
    /// Construct the window from an existing control
    ///
    /// \param Handle :            Platform-specific handle of the control
    /// \param AntialiasingLevel : Level of antialiasing (0 by default, disabled)
    ///
    ////////////////////////////////////////////////////////////
    Window(WindowHandle Handle, int AntialiasingLevel = 0);

    ////////////////////////////////////////////////////////////
    /// Destructor
    ///
    ////////////////////////////////////////////////////////////
    virtual ~Window();

    ////////////////////////////////////////////////////////////
    /// Create the window
    ///
    /// \param Mode :              Video mode to use
    /// \param Title :             Title of the window
    /// \param WindowStyle :       Window style (resizable by default)
    /// \param AntialiasingLevel : Level of antialiasing (0 by default, disabled)
    ///
    ////////////////////////////////////////////////////////////
    void Create(VideoMode Mode, const std::string& Title, Style WindowStyle = Resizable, int AntialiasingLevel = 0);

    ////////////////////////////////////////////////////////////
    /// Create the window from an existing control
    ///
    /// \param Handle :            Platform-specific handle of the control
    /// \param AntialiasingLevel : Level of antialiasing (0 by default, disabled)
    ///
    ////////////////////////////////////////////////////////////
    void Create(WindowHandle Handle, int AntialiasingLevel = 0);

    ////////////////////////////////////////////////////////////
    /// Get the width of the rendering region of the window
    ///
    /// \return Width in pixels
    ///
    ////////////////////////////////////////////////////////////
    unsigned int GetWidth() const;

    ////////////////////////////////////////////////////////////
    /// Get the height of the rendering region of the window
    ///
    /// \return Height in pixels
    ///
    ////////////////////////////////////////////////////////////
    unsigned int GetHeight() const;

    ////////////////////////////////////////////////////////////
    /// Get the depth buffer bits
    ///
    /// \return Depth bits (can be 0 if there is no depth buffer)
    ///
    ////////////////////////////////////////////////////////////
    unsigned int GetDepthBits() const;

    ////////////////////////////////////////////////////////////
    /// Get the stencil buffer bits
    ///
    /// \return Stencil bits (can be 0 if there is no stencil buffer)
    ///
    ////////////////////////////////////////////////////////////
    unsigned int GetStencilBits() const;

    ////////////////////////////////////////////////////////////
    /// Get the event on top of events stack, if any, and pop it
    ///
    /// \param EventReceived : Event to fill, if any
    ///
    /// \return True if an event was returned, false if events stack was empty
    ///
    ////////////////////////////////////////////////////////////
    bool GetEvent(Event& EventReceived);

    ////////////////////////////////////////////////////////////
    /// Enable / disable vertical synchronization
    ///
    /// \param Enabled : True to enable v-sync, false to deactivate
    ///
    ////////////////////////////////////////////////////////////
    void UseVerticalSync(bool Enabled);

    ////////////////////////////////////////////////////////////
    /// Show or hide the mouse cursor
    ///
    /// \param Show : True to show, false to hide
    ///
    ////////////////////////////////////////////////////////////
    void ShowMouseCursor(bool Show);

    ////////////////////////////////////////////////////////////
    /// Change the position of the window on screen.
    /// Only works for top-level windows
    ///
    /// \param Left : Left position
    /// \param Top :  Top position
    ///
    ////////////////////////////////////////////////////////////
    void SetPosition(int Left, int Top);

    ////////////////////////////////////////////////////////////
    /// Set the window as the current target for rendering
    ///
    /// \return True if operation was successful, false otherwise
    ///
    ////////////////////////////////////////////////////////////
    bool SetCurrent() const;

    ////////////////////////////////////////////////////////////
    /// Display the window on screen
    ///
    ////////////////////////////////////////////////////////////
    void Display();

    ////////////////////////////////////////////////////////////
    /// Get the input manager of the window
    ///
    /// \return Reference to the input
    ///
    ////////////////////////////////////////////////////////////
    const Input& GetInput() const;

    ////////////////////////////////////////////////////////////
    /// Limit the framerate to a maximum fixed frequency
    ///
    /// \param Limit : Framerate limit, in frames per seconds (use 0 to disable limit)
    ///
    ////////////////////////////////////////////////////////////
    void SetFramerateLimit(unsigned int Limit);

    ////////////////////////////////////////////////////////////
    /// Get time elapsed since last frame
    ///
    /// \return Time elapsed, in seconds
    ///
    ////////////////////////////////////////////////////////////
    float GetFrameTime() const;

private :

    ////////////////////////////////////////////////////////////
    /// /see WindowListener::OnEvent
    ///
    ////////////////////////////////////////////////////////////
    virtual void OnEvent(const Event& EventReceived);

    ////////////////////////////////////////////////////////////
    /// Initialize internal window
    ///
    /// \param Impl : New internal window implementation
    ///
    ////////////////////////////////////////////////////////////
    void Initialize(priv::WindowImpl* Impl);

    ////////////////////////////////////////////////////////////
    // Member data
    ////////////////////////////////////////////////////////////
    priv::WindowImpl* myWindow;         ///< Platform-specific implementation of window
    std::queue<Event> myEvents;         ///< Queue of received events
    Input             myInput;          ///< Input manager connected to window
    Clock             myClock;          ///< Clock for measuring the elapsed time between frames
    float             myLastFrameTime;  ///< Time elapsed since last frame
    bool              myIsExternal;     ///< Tell whether the window is internal or external (created by SFML or not)
    unsigned int      myFramerateLimit; ///< Current framerate limit
};

} // namespace sf


#endif // SFML_WINDOW_HPP
