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

#ifndef SFML_SOUND_HPP
#define SFML_SOUND_HPP

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <cstdlib>
#include <SFML/Audio/AudioResource.hpp>


namespace sf
{
class SoundBuffer;

////////////////////////////////////////////////////////////
/// Sound defines the properties of the sound such as position,
/// volume, pitch, etc.
////////////////////////////////////////////////////////////
class SFML_API Sound : public AudioResource
{
public :

    ////////////////////////////////////////////////////////////
    /// Enumeration of the sound states
    ////////////////////////////////////////////////////////////
    enum Status
    {
        Stopped, ///< Sound is not playing
        Paused,  ///< Sound is paused
        Playing  ///< Sound is playing
    };

    ////////////////////////////////////////////////////////////
    /// Construct the sound from its parameters
    ///
    /// \param Buffer : Sound buffer to play (NULL by default)
    /// \param Loop :   Loop flag (false by default)
    /// \param Pitch :  Value of the pitch (1 by default)
    /// \param Volume : Volume (100 by default)
    /// \param X :      X position (0 by default)
    /// \param Y :      Y position (0 by default)
    /// \param Z :      Z position (0 by default)
    ///
    ////////////////////////////////////////////////////////////
    Sound(const SoundBuffer* Buffer = NULL, bool Loop = false, float Pitch = 1.f, float Volume = 100.f, float X = 0.f, float Y = 0.f, float Z = 0.f);

    ////////////////////////////////////////////////////////////
    /// Copy constructor
    ///
    /// \param Copy : Instance to copy
    ///
    ////////////////////////////////////////////////////////////
    Sound(const Sound& Copy);

    ////////////////////////////////////////////////////////////
    /// Destructor
    ///
    ////////////////////////////////////////////////////////////
    ~Sound();

    ////////////////////////////////////////////////////////////
    /// Play the sound
    ///
    ////////////////////////////////////////////////////////////
    void Play();

    ////////////////////////////////////////////////////////////
    /// Pause the sound
    ///
    ////////////////////////////////////////////////////////////
    void Pause();

    ////////////////////////////////////////////////////////////
    /// Stop the sound
    ///
    ////////////////////////////////////////////////////////////
    void Stop();

    ////////////////////////////////////////////////////////////
    /// Set the source buffer
    ///
    /// \param Buffer : Pointer to the new sound buffer to bind to the sound
    ///
    ////////////////////////////////////////////////////////////
    void SetBuffer(const SoundBuffer* Buffer);

    ////////////////////////////////////////////////////////////
    /// Set the sound loop state
    ///
    /// \param Loop : True to play in loop, false to play once
    ///
    ////////////////////////////////////////////////////////////
    void SetLoop(bool Loop);

    ////////////////////////////////////////////////////////////
    /// Set the sound pitch
    ///
    /// \param Pitch : New pitch
    ///
    ////////////////////////////////////////////////////////////
    void SetPitch(float Pitch);

    ////////////////////////////////////////////////////////////
    /// Set the sound volume
    ///
    /// \param Volume : Volume (in range [0, 100])
    ///
    ////////////////////////////////////////////////////////////
    void SetVolume(float Volume);

    ////////////////////////////////////////////////////////////
    /// Set the sound position
    ///
    /// \param X : X position of the sound in the world
    /// \param Y : Y position of the sound in the world
    /// \param Z : Z position of the sound in the world
    ///
    ////////////////////////////////////////////////////////////
    void SetPosition(float X, float Y, float Z);

    ////////////////////////////////////////////////////////////
    /// Get the source buffer
    ///
    /// \return Sound buffer bound to the sound (can be NULL)
    ///
    ////////////////////////////////////////////////////////////
    const SoundBuffer* GetBuffer() const;

    ////////////////////////////////////////////////////////////
    /// Tell whether or not the sound is looping
    ///
    /// \return True if the sound is looping, false otherwise
    ///
    ////////////////////////////////////////////////////////////
    bool GetLoop() const;

    ////////////////////////////////////////////////////////////
    /// Get the pitch
    ///
    /// \return Pitch value
    ///
    ////////////////////////////////////////////////////////////
    float GetPitch() const;

    ////////////////////////////////////////////////////////////
    /// Get the volume
    ///
    /// \return Volume value (in range [1, 100])
    ///
    ////////////////////////////////////////////////////////////
    float GetVolume() const;

    ////////////////////////////////////////////////////////////
    /// Get the sound position
    ///
    /// \param X : X position of the sound in the world
    /// \param Y : Y position of the sound in the world
    /// \param Z : Z position of the sound in the world
    ///
    ////////////////////////////////////////////////////////////
    void GetPosition(float& X, float& Y, float& Z) const;

    ////////////////////////////////////////////////////////////
    /// Get the status of the sound (stopped, paused, playing)
    ///
    /// \return Current status of the sound
    ///
    ////////////////////////////////////////////////////////////
    Status GetStatus() const;

    ////////////////////////////////////////////////////////////
    /// Get the current playing position of the sound
    ///
    /// \return Current playing position, expressed in seconds
    ///
    ////////////////////////////////////////////////////////////
    float GetPlayingOffset() const;

    ////////////////////////////////////////////////////////////
    /// Assignment operator
    ///
    /// \param Other : Instance to assign
    ///
    /// \return Reference to the sound
    ///
    ////////////////////////////////////////////////////////////
    Sound& operator =(const Sound& Other);

private :

    friend class SoundStream;

    ////////////////////////////////////////////////////////////
    // Member data
    ////////////////////////////////////////////////////////////
    unsigned int       mySource; ///< OpenAL source identifier
    const SoundBuffer* myBuffer; ///< Sound buffer bound to the source
};

} // namespace sf


#endif // SFML_SOUND_HPP
