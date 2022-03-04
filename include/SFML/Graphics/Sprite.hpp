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

#ifndef SFML_SPRITE_HPP
#define SFML_SPRITE_HPP

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Rect.hpp>


namespace sf
{
class Image;

////////////////////////////////////////////////////////////
/// Sprite defines a sprite : texture, transformations,
/// color, and draw on screen
////////////////////////////////////////////////////////////
class SFML_API Sprite : public Drawable
{
public :

    ////////////////////////////////////////////////////////////
    /// Default constructor
    ///
    ////////////////////////////////////////////////////////////
    Sprite();

    ////////////////////////////////////////////////////////////
    /// Construct the sprite from a source image
    ///
    /// \param Img :      Image of the sprite
    /// \param Left :     Left coordinate of the sprite (0 by default)
    /// \param Top :      Top coordinate of the sprite (0 by default)
    /// \param ScaleX :   Horizontal scale (1 by default)
    /// \param ScaleY :   Vertical scale (1 by default)
    /// \param Rotation : Orientation, in degrees (0 by default)
    /// \param Col :      Color of the sprite (white by default)
    ///
    ////////////////////////////////////////////////////////////
    Sprite(const Image& Img, float Left = 0.f, float Top = 0.f, float ScaleX = 1.f, float ScaleY = 1.f, float Rotation = 0.f, const Color& Col = Color(255, 255, 255, 255));

    ////////////////////////////////////////////////////////////
    /// Change the image of the sprite
    ///
    /// \param Img : New image
    ///
    ////////////////////////////////////////////////////////////
    void SetImage(const Image& Img);

    ////////////////////////////////////////////////////////////
    /// Set the sub-rectangle of the sprite inside the source image
    ///
    /// \param SubRect : New sub-rectangle
    ///
    ////////////////////////////////////////////////////////////
    void SetSubRect(const IntRect& SubRect);

    ////////////////////////////////////////////////////////////
    /// Resize the sprite (by changing its scale factors)
    ///
    /// \param Width :  New width (must be strictly positive)
    /// \param Height : New height (must be strictly positive)
    ///
    ////////////////////////////////////////////////////////////
    void Resize(float Width, float Height);

    ////////////////////////////////////////////////////////////
    /// Get the source image of the sprite
    ///
    /// \return Pointer to the image (can be NULL)
    ///
    ////////////////////////////////////////////////////////////
    const Image* GetImage() const;

    ////////////////////////////////////////////////////////////
    /// Get the sub-rectangle of the sprite inside the source image
    ///
    /// \return Sub-rectangle
    ///
    ////////////////////////////////////////////////////////////
    const IntRect& GetSubRect() const;

    ////////////////////////////////////////////////////////////
    /// Get the sprite width
    ///
    /// \return Width of the sprite
    ///
    ////////////////////////////////////////////////////////////
    float GetWidth() const;

    ////////////////////////////////////////////////////////////
    /// Get the sprite height
    ///
    /// \return Height of the sprite
    ///
    ////////////////////////////////////////////////////////////
    float GetHeight() const;

    ////////////////////////////////////////////////////////////
    /// Get the color of a given pixel in the sprite
    ///
    /// \param X : X coordinate of the pixel to get
    /// \param Y : Y coordinate of the pixel to get
    ///
    /// \return Color of pixel (X, Y)
    ///
    ////////////////////////////////////////////////////////////
    Color GetPixel(unsigned int X, unsigned int Y) const;

protected :

    ////////////////////////////////////////////////////////////
    /// /see Drawable::Render
    ///
    ////////////////////////////////////////////////////////////
    virtual void Render(RenderWindow& Window);

private :

    ////////////////////////////////////////////////////////////
    // Member data
    ////////////////////////////////////////////////////////////
    const Image* myImage;    ///< Image used to draw the sprite
    IntRect      mySubRect;  ///< Sub-rectangle of source image to assign to the sprite
};

} // namespace sf


#endif // SFML_SPRITE_HPP
