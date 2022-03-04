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

#ifndef SFML_RENDERWINDOW_HPP
#define SFML_RENDERWINDOW_HPP

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Image.hpp>
#include <SFML/Graphics/View.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Window/Window.hpp>
#include <string>


namespace sf
{
class Drawable;

////////////////////////////////////////////////////////////
/// Simple wrapper for sfWindow that allows easy
/// 2D rendering
////////////////////////////////////////////////////////////
class SFML_API RenderWindow : private Window
{
public :

    using Window::Style;
    using Window::Resizable;
    using Window::Fixed;
    using Window::Fullscreen;

    using Window::GetWidth;
    using Window::GetHeight;
    using Window::GetInput;
    using Window::GetFrameTime;
    using Window::GetDepthBits;
    using Window::GetStencilBits;
    using Window::UseVerticalSync;
    using Window::ShowMouseCursor;
    using Window::SetPosition;
    using Window::SetFramerateLimit;

    ////////////////////////////////////////////////////////////
    /// Default constructor
    ///
    ////////////////////////////////////////////////////////////
    RenderWindow();

    ////////////////////////////////////////////////////////////
    /// Construct the window
    ///
    /// \param Mode :              Video mode to use
    /// \param Title :             Title of the window
    /// \param WindowStyle :       Window style (resizable by default)
    /// \param AntialiasingLevel : Level of antialiasing (0 by default, disabled)
    ///
    ////////////////////////////////////////////////////////////
    RenderWindow(VideoMode Mode, const std::string& Title, Style WindowStyle = Resizable, int AntialiasingLevel = 0);

    ////////////////////////////////////////////////////////////
    /// Construct the window from an existing control
    ///
    /// \param Handle :            Platform-specific handle of the control
    /// \param AntialiasingLevel : Level of antialiasing (0 by default, disabled)
    ///
    ////////////////////////////////////////////////////////////
    RenderWindow(WindowHandle Handle, int AntialiasingLevel = 0);

    ////////////////////////////////////////////////////////////
    /// Destructor
    ///
    ////////////////////////////////////////////////////////////
    virtual ~RenderWindow();

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
    /// Display window content on screen
    ///
    ////////////////////////////////////////////////////////////
    void Display();

    ////////////////////////////////////////////////////////////
    /// Draw something on the window
    ///
    /// \param Object : Object to draw
    ///
    ////////////////////////////////////////////////////////////
    void Draw(Drawable& Object);

    ////////////////////////////////////////////////////////////
    /// Save the content of the window to an image
    ///
    /// \return Image instance containing the contents of the screen
    ///
    ////////////////////////////////////////////////////////////
    Image Capture() const;

    ////////////////////////////////////////////////////////////
    /// Change the background color of the window
    ///
    /// \param Col : New background color
    ///
    ////////////////////////////////////////////////////////////
    void SetBackgroundColor(const Color& Col);

    ////////////////////////////////////////////////////////////
    /// Get the event on top of events stack, if any
    ///
    /// \param EventReceived : Event to fill, if any
    ///
    /// \return True if an event was returned, false if events stack was empty
    ///
    ////////////////////////////////////////////////////////////
    bool GetEvent(Event& EventReceived);

    ////////////////////////////////////////////////////////////
    /// Change the current active view
    ///
    /// \param NewView : Pointer to the new view (pass NULL to set the default view)
    ///
    ////////////////////////////////////////////////////////////
    void SetView(const View* NewView);

    ////////////////////////////////////////////////////////////
    /// Get the current view rectangle
    ///
    /// \return Current view rectangle, in global coordinates
    ///
    ////////////////////////////////////////////////////////////
    const FloatRect& GetViewRect() const;

    ////////////////////////////////////////////////////////////
    /// Start custom OpenGL rendering
    ///
    ////////////////////////////////////////////////////////////
    void BeginOpenGL();

    ////////////////////////////////////////////////////////////
    /// End custom OpenGL rendering
    ///
    ////////////////////////////////////////////////////////////
    void EndOpenGL();

private :

    ////////////////////////////////////////////////////////////
    /// Initialize internal window
    ///
    ////////////////////////////////////////////////////////////
    void Initialize();

    ////////////////////////////////////////////////////////////
    // Member data
    ////////////////////////////////////////////////////////////
    Color     myBackgroundColor; ///< Background color
    View      myDefaultView;     ///< Default view
    FloatRect myCurrentRect;     ///< Rectangle corresponding to the current view
    bool      myOpenGLMode;      ///< True when we are between BeginOpenGL() and EndOpenGL()
};

} // namespace sf


#endif // SFML_RENDERWINDOW_HPP
