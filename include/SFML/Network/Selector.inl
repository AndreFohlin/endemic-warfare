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


////////////////////////////////////////////////////////////
/// Default constructor
////////////////////////////////////////////////////////////
template <typename Type>
Selector<Type>::Selector() :
myMaxSocket(0)
{
    Clear();
}


////////////////////////////////////////////////////////////
/// Add a socket to watch
////////////////////////////////////////////////////////////
template <typename Type>
void Selector<Type>::Add(Type Socket)
{
    FD_SET(Socket.mySocket, &mySet);

    if (static_cast<int>(Socket.mySocket) > myMaxSocket)
        myMaxSocket = static_cast<int>(Socket.mySocket);
}


////////////////////////////////////////////////////////////
/// Remove a socket
////////////////////////////////////////////////////////////
template <typename Type>
void Selector<Type>::Remove(Type Socket)
{
    FD_CLR(Socket.mySocket, &mySet);
}


////////////////////////////////////////////////////////////
/// Remove all sockets
////////////////////////////////////////////////////////////
template <typename Type>
void Selector<Type>::Clear()
{
    FD_ZERO(&mySet);

    myMaxSocket = 0;
}


////////////////////////////////////////////////////////////
/// Remove a socket
////////////////////////////////////////////////////////////
template <typename Type>
bool Selector<Type>::GetSocketsReady(std::vector<Type>& Sockets, float Timeout)
{
    // First of all, clear the array to fill...
    Sockets.clear();

    // Setup the timeout structure
    timeval Time;
    Time.tv_sec  = static_cast<long>(Timeout);
    Time.tv_usec = (static_cast<long>(Timeout * 1000) % 1000) * 1000;

    // Use a copy of the set, as it will be modified by select()
    fd_set Set = mySet;

    // Wait until one of the sockets is ready for reading, or timeout is reached
    if (select(myMaxSocket + 1, &Set, NULL, NULL, Timeout > 0 ? &Time : NULL) != 0)
    {
        // One or more sockets are ready : put them into the array
        for (int i = 0; i < myMaxSocket + 1; ++i)
        {
            if (FD_ISSET(i, &Set))
                Sockets.push_back(Type(static_cast<priv::SocketType>(i)));
        }

        return true;
    }
    else
    {
        // Timeout reached...
        return false;
    }
}
