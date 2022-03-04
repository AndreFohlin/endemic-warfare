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

#ifndef SFML_VIEW_HPP
#define SFML_VIEW_HPP

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <SFML/Config.hpp>


namespace sf
{
////////////////////////////////////////////////////////////
/// This class defines a view (position, size and zoom) ;
/// you can consider it as a camera
////////////////////////////////////////////////////////////
class SFML_API View
{
public :

    ////////////////////////////////////////////////////////////
    /// Default constructor
    ///
    ////////////////////////////////////////////////////////////
    View();

    ////////////////////////////////////////////////////////////
    /// Construct the view with position and size
    ///
    /// \param ViewLeft :   Left position of view
    /// \param ViewTop :    Top position of view
    /// \param ViewWidth :  Width of view
    /// \param ViewHeight : Height of view
    /// \param ViewZoom :   Zoom (1 by default)
    ///
    ////////////////////////////////////////////////////////////
    View(float ViewLeft, float ViewTop, float ViewWidth, float ViewHeight, float ViewZoom = 1.f);

    ////////////////////////////////////////////////////////////
    // Member data
    ////////////////////////////////////////////////////////////
    float Left;   ///< Left position of view
    float Top;    ///< Top position of view
    float Width;  ///< Width of view
    float Height; ///< Height of view
    float Zoom;   ///< Zoom (less than 1 is unzoom, greater than 1 is zoom)
};

} // namespace sf


#endif // SFML_VIEW_HPP
