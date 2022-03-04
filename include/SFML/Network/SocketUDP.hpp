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

#ifndef SFML_SOCKETUDP_HPP
#define SFML_SOCKETUDP_HPP

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <SFML/Network/Sockets.hpp>
#include <cstddef>


namespace sf
{
class Packet;
class IPAddress;
template <typename> class Selector;

////////////////////////////////////////////////////////////
/// SocketUDP wraps a socket using UDP protocol to
/// send data fastly (but with less safety)
////////////////////////////////////////////////////////////
class SFML_API SocketUDP
{
public :

    ////////////////////////////////////////////////////////////
    /// Default constructor
    ///
    ////////////////////////////////////////////////////////////
    SocketUDP();

    ////////////////////////////////////////////////////////////
    /// Send an array of bytes
    ///
    /// \param Data :    Pointer to the bytes to send
    /// \param Size :    Number of bytes to send
    /// \param Address : Address of the computer to send the packet to
    /// \param Port :    Port to use for communication
    ///
    /// \return True if operation has been successful
    ///
    ////////////////////////////////////////////////////////////
    bool Send(const char* Data, std::size_t Size, const IPAddress& Address, unsigned short Port);

    ////////////////////////////////////////////////////////////
    /// Receive an array of bytes.
    /// This function is blocking, ie. it won't return before some
    /// bytes have been received
    ///
    /// \param Data :         Pointer to a byte array to fill (make sure it is big enough)
    /// \param MaxSize :      Maximum number of bytes to read
    /// \param SizeReceived : Number of bytes received
    /// \param Address :      Address of the computer to send the packet to
    /// \param Port :         Port to use for communication
    ///
    /// \return True if operation has been successful
    ///
    ////////////////////////////////////////////////////////////
    bool Receive(char* Data, std::size_t MaxSize, std::size_t& SizeReceived, IPAddress& Address, unsigned short Port);

    ////////////////////////////////////////////////////////////
    /// Send a packet of data
    ///
    /// \param PacketToSend : Packet to send
    /// \param Address :      Address of the computer to send the packet to
    /// \param Port :         Port to use for communication
    ///
    /// \return True if operation has been successful
    ///
    ////////////////////////////////////////////////////////////
    bool Send(Packet& PacketToSend, const IPAddress& Address, unsigned short Port);

    ////////////////////////////////////////////////////////////
    /// Receive a packet.
    /// This function is blocking, ie. it won't return before a
    /// packet is received
    ///
    /// \param PacketToReceive : Packet to fill with received data
    /// \param Address :         Address of the computer that sent the packet
    /// \param Port :            Port to use for communication
    ///
    /// \return True if operation has been successful
    ///
    ////////////////////////////////////////////////////////////
    bool Receive(Packet& PacketToReceive, IPAddress& Address, unsigned short Port);

    ////////////////////////////////////////////////////////////
    /// Close the socket
    ///
    /// \return True if operation has been successful
    ///
    ////////////////////////////////////////////////////////////
    bool Close();

    ////////////////////////////////////////////////////////////
    /// Comparison operator ==
    ///
    /// \param Other : Socket to compare
    ///
    /// \return True if *this == Other
    ///
    ////////////////////////////////////////////////////////////
    bool operator ==(const SocketUDP& Other) const;

    ////////////////////////////////////////////////////////////
    /// Comparison operator !=
    ///
    /// \param Other : Socket to compare
    ///
    /// \return True if *this != Other
    ///
    ////////////////////////////////////////////////////////////
    bool operator !=(const SocketUDP& Other) const;

    ////////////////////////////////////////////////////////////
    /// Comparison operator <.
    /// Provided for compatibility with standard containers, as
    /// comparing two sockets doesn't make much sense...
    ///
    /// \param Other : Socket to compare
    ///
    /// \return True if *this < Other
    ///
    ////////////////////////////////////////////////////////////
    bool operator <(const SocketUDP& Other) const;

private :

    friend class Selector<SocketUDP>;

    ////////////////////////////////////////////////////////////
    /// Construct the socket from a socket descriptor
    /// (for internal use only)
    ///
    /// \param Descriptor : Socket descriptor
    ///
    ////////////////////////////////////////////////////////////
    SocketUDP(priv::SocketType Descriptor);

    ////////////////////////////////////////////////////////////
    /// Create the socket
    ///
    ////////////////////////////////////////////////////////////
    void Create();

    ////////////////////////////////////////////////////////////
    // Member data
    ////////////////////////////////////////////////////////////
    priv::SocketType mySocket; ///< Socket identifier
    unsigned short   myPort;   ///< Port to which the socket is bound
};

} // namespace sf


#endif // SFML_SOCKETUDP_HPP
