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

#ifndef SFML_SELECTOR_HPP
#define SFML_SELECTOR_HPP

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <SFML/Network/SocketUDP.hpp>
#include <SFML/Network/SocketTCP.hpp>
#include <vector>


namespace sf
{
////////////////////////////////////////////////////////////
/// Selector allow reading from multiple sockets
/// without blocking. It's a kind of multiplexer
////////////////////////////////////////////////////////////
template <typename Type>
class Selector
{
public :

    ////////////////////////////////////////////////////////////
    /// Default constructor
    ///
    ////////////////////////////////////////////////////////////
    Selector();

    ////////////////////////////////////////////////////////////
    /// Add a socket to watch
    ///
    /// \param Socket : Socket to add
    ///
    ////////////////////////////////////////////////////////////
    void Add(Type Socket);

    ////////////////////////////////////////////////////////////
    /// Remove a socket
    ///
    /// \param Socket : Socket to remove
    ///
    ////////////////////////////////////////////////////////////
    void Remove(Type Socket);

    ////////////////////////////////////////////////////////////
    /// Remove all sockets
    ///
    ////////////////////////////////////////////////////////////
    void Clear();

    ////////////////////////////////////////////////////////////
    /// Remove a socket
    ///
    /// \param Sockets : Array to fill with sockets that are ready for reading
    /// \param Timeout : Timeout, in seconds (0 by default : no timeout)
    ///
    /// \return True if a socket is ready, false if time was out
    ///
    ////////////////////////////////////////////////////////////
    bool GetSocketsReady(std::vector<Type>& Sockets, float Timeout = 0.f);

private :

    ////////////////////////////////////////////////////////////
    // Member data
    ////////////////////////////////////////////////////////////
    fd_set mySet;       ///< Set of socket to watch
    int    myMaxSocket; ///< Maximum socket index
};

#include <SFML/Network/Selector.inl>

// Let's define the two only valid types of Selector
typedef Selector<SocketUDP> SelectorUDP;
typedef Selector<SocketTCP> SelectorTCP;

} // namespace sf


#endif // SFML_SELECTOR_HPP
