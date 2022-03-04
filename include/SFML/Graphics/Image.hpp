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

#ifndef SFML_IMAGE_HPP
#define SFML_IMAGE_HPP

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/VideoResource.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <string>
#include <vector>


namespace sf
{
////////////////////////////////////////////////////////////
/// Image is the low-level class for loading and
/// manipulating images
////////////////////////////////////////////////////////////
class SFML_API Image : public VideoResource
{
public :

    ////////////////////////////////////////////////////////////
    /// Default constructor
    ///
    ////////////////////////////////////////////////////////////
    Image();

    ////////////////////////////////////////////////////////////
    /// Copy constructor
    ///
    /// \param Copy : instance to copy
    ///
    ////////////////////////////////////////////////////////////
    Image(const Image& Copy);

    ////////////////////////////////////////////////////////////
    /// Construct an empty image
    ///
    /// \param Width :  Image width
    /// \param Height : Image height
    /// \param Col :    Image color (black by default)
    ///
    ////////////////////////////////////////////////////////////
    Image(unsigned int Width, unsigned int Height, const Color& Col = Color(0, 0, 0, 255));

    ////////////////////////////////////////////////////////////
    /// Construct the image from pixels in memory
    ///
    /// \param Width :  Image width
    /// \param Height : Image height
    /// \param Data :   Pointer to the pixels in memory (assumed format is RGBA 32 bits)
    ///
    ////////////////////////////////////////////////////////////
    Image(unsigned int Width, unsigned int Height, const void* Data);

    ////////////////////////////////////////////////////////////
    /// Destructor
    ///
    ////////////////////////////////////////////////////////////
    ~Image();

    ////////////////////////////////////////////////////////////
    /// Load the surface from a file
    ///
    /// \param Filename : Path of the image file to load
    ///
    /// \return True if loading was successful
    ///
    ////////////////////////////////////////////////////////////
    bool LoadFromFile(const std::string& Filename);

    ////////////////////////////////////////////////////////////
    /// Save the content of the image to a file
    ///
    /// \param Filename : Path of the file to save (overwritten if already exist)
    ///
    /// \return True if saving was successful
    ///
    ////////////////////////////////////////////////////////////
    bool SaveToFile(const std::string& Filename) const;

    ////////////////////////////////////////////////////////////
    /// Create an empty image
    ///
    /// \param Width :  Image width
    /// \param Height : Image height
    /// \param Col :    Image color (black by default)
    ///
    ////////////////////////////////////////////////////////////
    void Create(unsigned int Width, unsigned int Height, const Color& Col = Color(0, 0, 0, 255));

    ////////////////////////////////////////////////////////////
    /// Load the image from pixels in memory
    ///
    /// \param Width :  Image width
    /// \param Height : Image height
    /// \param Data :   Pointer to the pixels in memory (assumed format is RGBA 32 bits)
    ///
    ////////////////////////////////////////////////////////////
    void LoadFromMemory(unsigned int Width, unsigned int Height, const void* Data);

    ////////////////////////////////////////////////////////////
    /// Create transparency mask from a specified colorkey
    ///
    /// \param ColorKey : Color to become transparent
    /// \param Alpha :    Alpha value to use for transparent pixels (0 by default)
    ///
    ////////////////////////////////////////////////////////////
    void CreateMaskFromColor(const Color& ColorKey, Uint8 Alpha = 0);

    ////////////////////////////////////////////////////////////
    /// Resize the image - warning : this function does not scale the image,
    /// it just ajdusts size (add padding or remove pixels)
    ///
    /// \param Width :  New width
    /// \param Height : New height
    /// \param Col :    Color to assign to new pixels (black by default)
    ///
    ////////////////////////////////////////////////////////////
    void Resize(unsigned int Width, unsigned int Height, const Color& Col = Color(0, 0, 0, 255));

    ////////////////////////////////////////////////////////////
    /// Change the color of a pixel
    /// Don't forget to call Update when you end modifying pixels
    ///
    /// \param X :   X coordinate of pixel in the image
    /// \param Y :   Y coordinate of pixel in the image
    /// \param Col : New color for pixel (X, Y)
    ///
    ////////////////////////////////////////////////////////////
    void SetPixel(unsigned int X, unsigned int Y, const Color& Col);

    ////////////////////////////////////////////////////////////
    /// Get a pixel from the image
    ///
    /// \param X :   X coordinate of pixel in the image
    /// \param Y :   Y coordinate of pixel in the image
    ///
    /// \return Color of pixel (x, y)
    ///
    ////////////////////////////////////////////////////////////
    Color GetPixel(unsigned int X, unsigned int Y) const;

    ////////////////////////////////////////////////////////////
    /// Get a read-only pointer to the array of pixels (32 bits integer RGBA)
    /// Array size is GetWidth() x GetHeight()
    /// This pointer becomes invalid if you reload or resize the image
    ///
    /// \return Const pointer to the array of pixels
    ///
    ////////////////////////////////////////////////////////////
    const Uint32* GetPixelsPtr() const;

    ////////////////////////////////////////////////////////////
    /// Update image in video memory
    /// (use when you have modified pixels manually)
    ///
    ////////////////////////////////////////////////////////////
    void Update();

    ////////////////////////////////////////////////////////////
    /// Bind the image for rendering
    ///
    ////////////////////////////////////////////////////////////
    void Bind() const;

    ////////////////////////////////////////////////////////////
    /// Enable or disable image smooth filter
    ///
    /// \param Smooth : True to enable smoothing filter, false to disable it
    ///
    ////////////////////////////////////////////////////////////
    void SetSmooth(bool Smooth) const;

    ////////////////////////////////////////////////////////////
    /// Enable or disable image repeat mode
    /// (ie. how to define pixels outside the texture range)
    ///
    /// \param Repeat : True to enable repeat, false to disable
    ///
    ////////////////////////////////////////////////////////////
    void SetRepeat(bool Repeat) const;

    ////////////////////////////////////////////////////////////
    /// Return the width of the image
    ///
    /// \return Width in pixels
    ///
    ////////////////////////////////////////////////////////////
    unsigned int GetWidth() const;

    ////////////////////////////////////////////////////////////
    /// Return the height of the image
    ///
    /// \return Height in pixels
    ///
    ////////////////////////////////////////////////////////////
    unsigned int GetHeight() const;

    ////////////////////////////////////////////////////////////
    /// Convert a subrect expressed in pixels, into float
    /// texture coordinates
    ///
    /// \param Rect : Sub-rectangle of image to convert
    ///
    /// \return Texture coordinates corresponding to the sub-rectangle
    ///
    ////////////////////////////////////////////////////////////
    FloatRect GetTexCoords(const IntRect& Rect) const;

    ////////////////////////////////////////////////////////////
    /// Get a valid texture size according to hardware support
    ///
    /// \param Size : Size to convert
    ///
    /// \return Valid nearest size (greater than or equal to specified size)
    ///
    ////////////////////////////////////////////////////////////
    static unsigned int GetValidTextureSize(unsigned int Size);

    ////////////////////////////////////////////////////////////
    /// Assignment operator
    ///
    /// \param Other : instance to assign
    ///
    /// \return Reference to the image
    ///
    ////////////////////////////////////////////////////////////
    Image& operator =(const Image& Other);

private :

    ////////////////////////////////////////////////////////////
    /// Create the OpenGL texture
    ///
    ////////////////////////////////////////////////////////////
    void CreateTexture();

    ////////////////////////////////////////////////////////////
    /// /see sfVideoResource::DestroyVideoResources
    ///
    ////////////////////////////////////////////////////////////
    virtual void DestroyVideoResources();

    ////////////////////////////////////////////////////////////
    // Member data
    ////////////////////////////////////////////////////////////
    unsigned int        myWidth;         ///< Image width
    unsigned int        myHeight;        ///< Image Height
    unsigned int        myTextureWidth;  ///< Actual texture width (can be greater than image width because of padding)
    unsigned int        myTextureHeight; ///< Actual texture height (can be greater than image height because of padding)
    std::vector<Uint32> myPixels;        ///< Pixels of the image (32 bits BGRA)
    unsigned int        myGLTexture;     ///< OpenGL texture identifier
};

} // namespace sf


#endif // SFML_IMAGE_HPP
