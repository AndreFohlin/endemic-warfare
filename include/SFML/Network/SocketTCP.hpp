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

#ifndef SFML_SOCKETTCP_HPP
#define SFML_SOCKETTCP_HPP

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
/// SocketTCP wraps a socket using TCP protocol to
/// send data safely (but a bit slower)
////////////////////////////////////////////////////////////
class SFML_API SocketTCP
{
public :

    ////////////////////////////////////////////////////////////
    /// Default constructor
    ///
    ////////////////////////////////////////////////////////////
    SocketTCP();

    ////////////////////////////////////////////////////////////
    /// Connect to another computer on a specified port
    ///
    /// \param Port :        Port to use for transfers (warning : ports < 1024 are reserved)
    /// \param HostAddress : IP Address of the host to connect to
    ///
    /// \return True if operation has been successful
    ///
    ////////////////////////////////////////////////////////////
    bool Connect(unsigned short Port, const IPAddress& HostAddress);

    ////////////////////////////////////////////////////////////
    /// Listen to a specified port for incoming data or connections
    ///
    /// \param Port : Port to listen to
    ///
    /// \return True if operation has been successful
    ///
    ////////////////////////////////////////////////////////////
    bool Listen(unsigned short Port);

    ////////////////////////////////////////////////////////////
    /// Wait for a connection (must be listening to a port).
    /// This function is blocking, ie. it won't return before
    /// a connection has been accepted
    ///
    /// \param Address : Pointer to an address to fill with client infos (NULL by default)
    ///
    /// \return New socket for communicating with connected client
    ///
    ////////////////////////////////////////////////////////////
    SocketTCP Accept(IPAddress* Address = NULL);

    ////////////////////////////////////////////////////////////
    /// Send an array of bytes to the host (must be connected first)
    ///
    /// \param Data : Pointer to the bytes to send
    /// \param Size : Number of bytes to send
    ///
    /// \return True if operation has been successful
    ///         (false would mean the connection is broken)
    ///
    ////////////////////////////////////////////////////////////
    bool Send(const char* Data, std::size_t Size);

    ////////////////////////////////////////////////////////////
    /// Receive an array of bytes from the host (must be connected first).
    /// This function is blocking, ie. it won't return before some
    /// bytes have been received
    ///
    /// \param Data :         Pointer to a byte array to fill (make sure it is big enough)
    /// \param MaxSize :      Maximum number of bytes to read
    /// \param SizeReceived : Number of bytes received
    ///
    /// \return True if operation has been successful
    ///         (false would mean the connection is broken)
    ///
    ////////////////////////////////////////////////////////////
    bool Receive(char* Data, std::size_t MaxSize, std::size_t& SizeReceived);

    ////////////////////////////////////////////////////////////
    /// Send a packet of data to the host (must be connected first)
    ///
    /// \param PacketToSend : Packet to send
    ///
    /// \return True if operation has been successful
    ///         (false would mean the connection is broken)
    ///
    ////////////////////////////////////////////////////////////
    bool Send(Packet& PacketToSend);

    ////////////////////////////////////////////////////////////
    /// Receive a packet from the host (must be connected first).
    /// This function is blocking, ie. it won't return before a
    /// packet is received
    ///
    /// \param PacketToReceive : Packet to fill with received data
    ///
    /// \return True if operation has been successful
    ///         (false would mean the connection is broken)
    ///
    ////////////////////////////////////////////////////////////
    bool Receive(Packet& PacketToReceive);

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
    bool operator ==(const SocketTCP& Other) const;

    ////////////////////////////////////////////////////////////
    /// Comparison operator !=
    ///
    /// \param Other : Socket to compare
    ///
    /// \return True if *this != Other
    ///
    ////////////////////////////////////////////////////////////
    bool operator !=(const SocketTCP& Other) const;

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
    bool operator <(const SocketTCP& Other) const;

private :

    friend class Selector<SocketTCP>;

    ////////////////////////////////////////////////////////////
    /// Construct the socket from a socket descriptor
    /// (for internal use only)
    ///
    /// \param Descriptor : Socket descriptor
    ///
    ////////////////////////////////////////////////////////////
    SocketTCP(priv::SocketType Descriptor);

    ////////////////////////////////////////////////////////////
    // Member data
    ////////////////////////////////////////////////////////////
    priv::SocketType mySocket; ///< Socket descriptor
};

} // namespace sf


#endif // SFML_SOCKETTCP_HPP
