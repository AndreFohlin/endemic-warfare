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

#ifndef SFML_DRAWABLE_HPP
#define SFML_DRAWABLE_HPP

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <SFML/Graphics/Color.hpp>


namespace sf
{
class RenderWindow;

////////////////////////////////////////////////////////////
/// Abstract base class for every object that can be drawn
/// into a render window
////////////////////////////////////////////////////////////
class SFML_API Drawable
{
public :

    ////////////////////////////////////////////////////////////
    /// Default constructor
    ///
    /// \param Left :     Left coordinate of the object (0 by default)
    /// \param Top :      Top coordinate of the object (0 by default)
    /// \param ScaleX :   Horizontal scale (1 by default)
    /// \param ScaleY :   Vertical scale (1 by default)
    /// \param Rotation : Orientation, in degrees (0 by default)
    /// \param Col :      Color of the object (white by default)
    ///
    ////////////////////////////////////////////////////////////
    Drawable(float Left = 0.f, float Top = 0.f, float ScaleX = 1.f, float ScaleY = 1.f, float Rotation = 0.f, const Color& Col = Color(255, 255, 255, 255));

    ////////////////////////////////////////////////////////////
    /// Virtual destructor
    ///
    ////////////////////////////////////////////////////////////
    virtual ~Drawable();

    ////////////////////////////////////////////////////////////
    /// Set the left position of the object
    ///
    /// \param Left : New left position
    ///
    ////////////////////////////////////////////////////////////
    void SetLeft(float Left);

    ////////////////////////////////////////////////////////////
    /// Set the top position of the object
    ///
    /// \param Top : New top position
    ///
    ////////////////////////////////////////////////////////////
    void SetTop(float Top);

    ////////////////////////////////////////////////////////////
    /// Set the scale of the object
    ///
    /// \param ScaleX : New horizontal scale (must be strictly positive)
    /// \param ScaleY : New vertical scale (must be strictly positive)
    ///
    ////////////////////////////////////////////////////////////
    void SetScale(float ScaleX, float ScaleY);

    ////////////////////////////////////////////////////////////
    /// Set the orientation of the object
    ///
    /// \param Rotation : Angle of rotation, in degrees
    ///
    ////////////////////////////////////////////////////////////
    void SetRotation(float Rotation);

    ////////////////////////////////////////////////////////////
    /// Set the center of rotation, in coordinates relative to the
    /// object
    ///
    /// \param X : X coordinate of the center of rotation
    /// \param Y : Y coordinate of the center of rotation
    ///
    ////////////////////////////////////////////////////////////
    void SetRotationCenter(float X, float Y);

    ////////////////////////////////////////////////////////////
    /// Set the color of the object
    ///
    /// \param Col : New color
    ///
    ////////////////////////////////////////////////////////////
    void SetColor(const Color& Col);

    ////////////////////////////////////////////////////////////
    /// Get the left position of the object
    ///
    /// \return Current left position
    ///
    ////////////////////////////////////////////////////////////
    float GetLeft() const;

    ////////////////////////////////////////////////////////////
    /// Get the top position of the object
    ///
    /// \return Current top position
    ///
    ////////////////////////////////////////////////////////////
    float GetTop() const;

    ////////////////////////////////////////////////////////////
    /// Get the horizontal scale of the object
    ///
    /// \return Current X scale factor (always positive)
    ///
    ////////////////////////////////////////////////////////////
    float GetScaleX() const;

    ////////////////////////////////////////////////////////////
    /// Get the vertical scale of the object
    ///
    /// \return Current Y scale factor (always positive)
    ///
    ////////////////////////////////////////////////////////////
    float GetScaleY() const;

    ////////////////////////////////////////////////////////////
    /// Get the orientation of the object
    ///
    /// \return Current rotation, in degrees
    ///
    ////////////////////////////////////////////////////////////
    float GetRotation() const;

    ////////////////////////////////////////////////////////////
    /// Get the color of the object
    ///
    /// \return Current color
    ///
    ////////////////////////////////////////////////////////////
    const Color& GetColor() const;

    ////////////////////////////////////////////////////////////
    /// Move the object
    ///
    /// \param OffsetX : Offset on the X axis
    /// \param OffsetY : Offset on the Y axis
    ///
    ////////////////////////////////////////////////////////////
    void Move(float OffsetX, float OffsetY);

    ////////////////////////////////////////////////////////////
    /// Scale the object
    ///
    /// \param FactorX : Horizontal scaling factor (must be strictly positive)
    /// \param FactorY : Vertical scaling factor (must be strictly positive)
    ///
    ////////////////////////////////////////////////////////////
    void Scale(float FactorX, float FactorY);

    ////////////////////////////////////////////////////////////
    /// Rotate the object
    ///
    /// \param Angle : Angle of rotation, in degrees
    ///
    ////////////////////////////////////////////////////////////
    void Rotate(float Angle);

private :

    friend class RenderWindow;

    ////////////////////////////////////////////////////////////
    /// Draw the object into the specified window
    ///
    /// \param Window : Window into which draw the object
    ///
    ////////////////////////////////////////////////////////////
    void Draw(RenderWindow& Window);

    ////////////////////////////////////////////////////////////
    /// Render the specific geometry of the object
    ///
    /// \param Window : Window into which render the object
    ///
    ////////////////////////////////////////////////////////////
    virtual void Render(RenderWindow& Window) = 0;

    ////////////////////////////////////////////////////////////
    // Member data
    ////////////////////////////////////////////////////////////
    float myLeft;     ///< Left position of the object on screen
    float myTop;      ///< Top position of the object on screen
    float myScaleX;   ///< Horizontal scale of the object
    float myScaleY;   ///< Vertical scale of the object
    float myRotation; ///< Orientation of the object, in degrees
    float myCenterX;  ///< X coordinate of the center of rotation, relative to the object
    float myCenterY;  ///< Y coordinate of the center of rotation, relative to the object
    Color myColor;    ///< Overlay color of the object
};

} // namespace sf


#endif // SFML_DRAWABLE_HPP
