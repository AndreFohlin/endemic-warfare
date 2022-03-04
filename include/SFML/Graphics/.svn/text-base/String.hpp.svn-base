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

#ifndef SFML_STRING_HPP
#define SFML_STRING_HPP

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <string>


namespace sf
{
////////////////////////////////////////////////////////////
/// String defines a graphical 2D text, that can be drawn on screen
////////////////////////////////////////////////////////////
class SFML_API String : public Drawable
{
public :

    ////////////////////////////////////////////////////////////
    /// Construct the string from a multibyte text
    ///
    /// \param Text : Text assigned to the string ("" by default)
    /// \param Font : Font used to draw the string ("" by default - use default font)
    /// \param Size : Characters size, in pixels (32 by default)
    ///
    ////////////////////////////////////////////////////////////
    String(const std::string& Text, const std::string& Font = "", float Size = 32.f);

    ////////////////////////////////////////////////////////////
    /// Construct the string from a unicode text
    ///
    /// \param Text : Text assigned to the string ("" by default)
    /// \param Font : Font used to draw the string ("" by default - use default font)
    /// \param Size : Characters size, in pixels (32 by default)
    ///
    ////////////////////////////////////////////////////////////
    String(const std::wstring& Text = L"", const std::string& Font = "", float Size = 32.f);

    ////////////////////////////////////////////////////////////
    /// Preload a bitmap font (otherwise, it is done the first time the font is drawn)
    ///
    /// \param Font :    Font to load
    /// \param Size :    Requested character size
    /// \param Charset : Characters set to generate (empty by default - take the ASCII range [31, 255])
    ///
    ////////////////////////////////////////////////////////////
    static void PreloadFont(const std::string& Font, float Size, std::wstring Charset = L"");

    ////////////////////////////////////////////////////////////
    /// Set the text (from a multibyte string)
    ///
    /// \param Text : New text
    ///
    ////////////////////////////////////////////////////////////
    void SetText(const std::string& Text);

    ////////////////////////////////////////////////////////////
    /// Set the text (from a unicode string)
    ///
    /// \param Text : New text
    ///
    ////////////////////////////////////////////////////////////
    void SetText(const std::wstring& Text);

    ////////////////////////////////////////////////////////////
    /// Set the font of the string
    ///
    /// \param Font : Font filename
    ///
    ////////////////////////////////////////////////////////////
    void SetFont(const std::string& Font);

    ////////////////////////////////////////////////////////////
    /// Set the size of the string
    ///
    /// \param Size : New size, in pixels
    ///
    ////////////////////////////////////////////////////////////
    void SetSize(float Size);

    ////////////////////////////////////////////////////////////
    /// Get the text (returns a unicode string)
    ///
    /// \return Text
    ///
    ////////////////////////////////////////////////////////////
    const std::wstring& GetUnicodeText() const;

    ////////////////////////////////////////////////////////////
    /// Get the text (returns a multibyte string)
    ///
    /// \return Text
    ///
    ////////////////////////////////////////////////////////////
    std::string GetText() const;

    ////////////////////////////////////////////////////////////
    /// Get the font used by the string
    ///
    /// \return Font name
    ///
    ////////////////////////////////////////////////////////////
    const std::string& GetFont() const;

    ////////////////////////////////////////////////////////////
    /// Get the size of the characters
    ///
    /// \return Size of the characters
    ///
    ////////////////////////////////////////////////////////////
    float GetSize() const;

    ////////////////////////////////////////////////////////////
    /// Get the string rectangle on screen
    ///
    /// \return Rectangle contaning the string in screen coordinates
    ///
    ////////////////////////////////////////////////////////////
    FloatRect GetRect() const;

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
    std::wstring myText; ///< Text to display
    std::string  myFont; ///< Font used to display string
    float        mySize; ///< Size of characters (in pixels) (must be strictly positive)
};

} // namespace sf


#endif // SFML_STRING_HPP
