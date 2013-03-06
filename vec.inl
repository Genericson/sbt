/////////////////////////////////////////////////
//vec.inl
// Note: do not include this file directly, include vec.hpp
/////////////////////////////////////////////////
// Copyright (c) 2013, Harrison Leadlay
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//
//  1) Redistributions of source code must retain the above copyright notice,
//     this list of conditions and the following disclaimer.
//
//  2) Redistributions in binary form must reproduce the above copyright notice,
//     this list of conditions and the following disclaimer in the documentation
//     and/or other materials provided with the distribution.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
// THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
// PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR
// CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
// EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
// PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
// OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
// WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
// OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
// ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
/////////////////////////////////////////////////

#include <iostream>
#include <cmath>
#include <stdexcept>

namespace sbt
{

template <typename T, unsigned int L>
vec<T, L>::vec ()
{
    for(unsigned int i; i < length(); i++)
        d[i] = 0;
} //vec()

template <typename T, unsigned int L>
vec<T, L>::vec (const T value)
{
    for(unsigned int i = 0u; i < length(); i++)
        d[i] =  value;
} //vec(T)

template <typename T, unsigned int L>
vec<T, L>::vec (const vec<T, L>& v)
{
    for(unsigned int i = 0u; i < length(); i++)
        d[i] = v[i];
} //vec(vec)

template <typename T, unsigned int L>
vec<T, L>::vec (const T v[L])
{
    for(unsigned int i = 0; i < length(); i++)
        d[i] = v[i];
} //vec(T[L])

template <typename T, unsigned int L>
T& vec<T, L>::operator[] (const unsigned int index)
{
    return d[index];
} //operator[](uint)

template <typename T, unsigned int L>
const T& vec<T, L>::operator[] (const unsigned int index) const
{
    return d[index];
} //operator[](uint)

template <typename T, unsigned int L>
T vec<T, L>::get (const unsigned int index) const
{
    if( index < this->length())
        return d[index];
    else
        throw std::out_of_range("index too large"); //uint ensures not too small
    std::cerr<<"Could not throw out_of_range exception!\n";
} //get(uint)

template <typename T, unsigned int L>
const unsigned int vec<T, L>::length() const
{
    return this->len;
} //length()

template <typename T, unsigned int L>
const vec<T, L>& vec<T, L>::operator= (const vec& v)
{
    for(unsigned int i = 0; i < length(); i++)
        d[i] = v[i];
    return *this;
} //operator=(vec)

template <typename T, unsigned int L>
const vec<T, L>& vec<T, L>::operator= (const T v[L])
{
    for(unsigned int i = 0; i < length(); i++)
        d[i] = v[i];
    return *this;
} //operator=(T[L])

template <typename T, unsigned int L>
const vec<T, L> vec<T, L>::operator* (const vec<T, L>& v) const
{
    vec<T, L> temp;
    for(unsigned int i = 0; i < length(); i++)
        temp[i] = v[i] * d[i];
    return temp;
} //operator*(vec)

template <typename T, unsigned int L>
const vec<T, L> vec<T, L>::operator* (const T& s) const
{
    vec<T, L> temp;
    for(unsigned int i = 0; i < length(); i++)
        temp[i] = d[i] * s;
    return temp;
} //operator*(T)

template <typename T, unsigned int L>
vec<T, L> vec<T, L>::operator+ (const vec<T, L>& v) const
{
    vec<T, L> temp;
    for(int i = 0; i < length(); i++)
        temp[i] = d[i] * v;
    return temp;
} //operator+(vec)

template <typename T, unsigned int L>
bool vec<T, L>::operator== (const vec<T, L>& v) const
{
    unsigned int i = 0;
    // uses loop conditional to check if each set of components are equal
    for(; i < length() && d[i] == v[i]; i++);
    // returns true if loop completed (i < length() terminated loop,
    //     all component comparisons equal)
    // returns false if loop terminated (d[i] == v[i] terminated the loop,
    //     at least one set of components not equal)
    return i == length();
} //operator==(vec)

template <typename T, unsigned int L>
T vec<T, L>::norm() const
{
    T result = 0;
    for(unsigned int i = 0; i < length(); i++)
    {
        result = (d[i])*(d[i]) + result;
        std::cerr<<"result: "<<result<<std::endl;
    }
    return std::sqrt(result);
} //norm()

template <typename T, unsigned int L>
vec<T, L>  vec<T, L>::normalize() const
{
    T n = this->norm();
    vec<T, L> result = *this;
    for(unsigned int i = 0; i < this->length(); i++)
    {
        result[i] = result[i] / n;
    }
    return result;
} //normalize()

template <typename T, unsigned int L>
vec<T, L>::~vec()
{

} //~vec()

//=============================================//
// STATIC FUNCTIONS
//=============================================//

template <typename T, unsigned int L>
T dot(const vec<T, L>& a, const vec<T, L>& b)
{
    T result = 0;
    for(unsigned int i = 0; i < L; i++)
    {
        result += a[i] * b[i];
    }
    return result;
} //dot(vec, vec)

template <typename T, unsigned int L>
vec<T, 3u> cross(const vec<T, 3u>& a, const vec<T, 3u>& b)
{
    vec<T, L> r;
    r[0] = a[1]*b[2] - a[2]*b[1];
    r[1] = a[2]*b[0] - a[0]*b[2];
    r[2] = a[0]*b[1] - a[1]*b[0];
    return r;
} //cross(vec3, vec3)

} //namespace sbt
