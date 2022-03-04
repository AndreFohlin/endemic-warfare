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

#ifndef SFML_OPENGLCAPS_HPP
#define SFML_OPENGLCAPS_HPP

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <SFML/Config.hpp>
#include <SFML/Window/glew/glew.h>
#include <string>


namespace sf
{
namespace priv
{
    class WindowImpl;
}

////////////////////////////////////////////////////////////
/// Interface for requesting OpenGL extensions
/// and capabilities
////////////////////////////////////////////////////////////
class SFML_API OpenGLCaps
{
public :

    ////////////////////////////////////////////////////////////
    /// Check whether or not an OpenGL extension is supported
    ///
    /// \param Name : String identifier of the extension to check
    ///
    /// \return True if the extension is supported
    ///
    ////////////////////////////////////////////////////////////
    static bool CheckExtension(const std::string& Name);

    ////////////////////////////////////////////////////////////
    /// Return the maximum texture size
    ///
    /// \return Maximum texture size, in pixels
    ///
    ////////////////////////////////////////////////////////////
    static int GetMaxTextureSize();

    ////////////////////////////////////////////////////////////
    /// Return the maximum number of texture units available
    ///
    /// \return Maximum number of texture units
    ///
    ////////////////////////////////////////////////////////////
    static int GetMaxTextureUnits();

private :

    friend class priv::WindowImpl;

    ////////////////////////////////////////////////////////////
    /// Initialize the capabilities
    ///
    ////////////////////////////////////////////////////////////
    static void Initialize();
};

} // namespace sf


#endif // SFML_OPENGLCAPS_HPP
