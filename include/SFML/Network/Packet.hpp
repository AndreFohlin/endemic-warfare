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

#ifndef SFML_PACKET_HPP
#define SFML_PACKET_HPP

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <SFML/Config.hpp>
#include <string>
#include <vector>


namespace sf
{
////////////////////////////////////////////////////////////
/// Packet wraps data to send / to receive through the network
////////////////////////////////////////////////////////////
class SFML_API Packet
{
public :

    ////////////////////////////////////////////////////////////
    /// Default constructor
    ///
    ////////////////////////////////////////////////////////////
    Packet();

    ////////////////////////////////////////////////////////////
    /// Virtual destructor
    ///
    ////////////////////////////////////////////////////////////
    virtual ~Packet();

    ////////////////////////////////////////////////////////////
    /// Append data to the end of the packet
    ///
    /// \param Data :        Pointer to the bytes to append
    /// \param SizeInBytes : Number of bytes to append
    ///
    ////////////////////////////////////////////////////////////
    void Append(const void* Data, std::size_t SizeInBytes);

    ////////////////////////////////////////////////////////////
    /// Clear the packet data
    ///
    ////////////////////////////////////////////////////////////
    void Clear();

    ////////////////////////////////////////////////////////////
    /// Get a pointer to the data contained in the packet
    /// Warning : the returned pointer may be invalid after you
    /// append data to the packet
    ///
    /// \return Pointer to the data
    ///
    ////////////////////////////////////////////////////////////
    const char* GetData() const;

    ////////////////////////////////////////////////////////////
    /// Get the size of the data contained in the packet
    ///
    /// \return Data size, in bytes
    ///
    ////////////////////////////////////////////////////////////
    Uint32 GetDataSize() const;

    ////////////////////////////////////////////////////////////
    /// Operator >> overloads to extract data from the packet
    ///
    ////////////////////////////////////////////////////////////
    Packet& operator >>(Int8&        Data);
    Packet& operator >>(Uint8&       Data);
    Packet& operator >>(Int16&       Data);
    Packet& operator >>(Uint16&      Data);
    Packet& operator >>(Int32&       Data);
    Packet& operator >>(Uint32&      Data);
    Packet& operator >>(float&       Data);
    Packet& operator >>(double&      Data);
    Packet& operator >>(char*        Data);
    Packet& operator >>(std::string& Data);

    ////////////////////////////////////////////////////////////
    /// Operator << overloads to put data into the packet
    ///
    ////////////////////////////////////////////////////////////
    Packet& operator <<(Int8               Data);
    Packet& operator <<(Uint8              Data);
    Packet& operator <<(Int16              Data);
    Packet& operator <<(Uint16             Data);
    Packet& operator <<(Int32              Data);
    Packet& operator <<(Uint32             Data);
    Packet& operator <<(float              Data);
    Packet& operator <<(double             Data);
    Packet& operator <<(const char*        Data);
    Packet& operator <<(const std::string& Data);

private :

    friend class SocketTCP;
    friend class SocketUDP;

    ////////////////////////////////////////////////////////////
    /// Called before the packet is sent to the network
    ///
    ////////////////////////////////////////////////////////////
    virtual void OnSend();

    ////////////////////////////////////////////////////////////
    /// Called after the packet has been received from the network
    ///
    ////////////////////////////////////////////////////////////
    virtual void OnReceive();

    ////////////////////////////////////////////////////////////
    // Member data
    ////////////////////////////////////////////////////////////
    std::vector<char> myData;    ///< Data stored in the packet
    std::size_t       myReadPos; ///< Current reading position in the packet
};

} // namespace sf


#endif // SFML_PACKET_HPP
