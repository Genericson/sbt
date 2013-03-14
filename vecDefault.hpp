#ifndef vec_default_HPP_
#define vec_default_HPP_

/////////////////////////////////////////////////
// vecDefault.hpp
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
//General design comments
//=============================================//
//
//
//
/////////////////////////////////////////////////


//=============================================//
// INCLUDE PROTOTYPE
//=============================================//
#include "vec.hpp"


//=============================================//
// INCLUDE IMPLEMENTATION
// Template implementation inserted directly into header
//=============================================//
#include "vecDefault.inl"


//=============================================//
// Template Aliases
//=============================================//

/////////////////////////////////////////////////
/// \brief single-precision floating point vectors
///
/// This name space includes separate classes for `float`
/// type 2-4 dimensional vectors
///
/////////////////////////////////////////////////
namespace sbt
{
namespace fvec
{
using vec2 = vec<float, 2u>;
using vec3 = vec<float, 3u>;
using vec4 = vec<float, 4u>;
} //fvec namespace

/////////////////////////////////////////////////
/// \brief double-precision floating point vectors
///
/// This name space includes separate classes for `double`
/// type 2-4 dimensional vectors
///
/////////////////////////////////////////////////
namespace dvec
{
using dvec2 = vec<double, 2u>;
using dvec3 = vec<double, 3u>;
using dvec4 = vec<double, 4u>;
} //dvec namespace

/////////////////////////////////////////////////
/// \brief Boolean vectors
///
/// This name space includes separate classes for `bool`
/// type 2-4 dimensional vectors
/////////////////////////////////////////////////
namespace bvec
{
using bvecd2 = vec<bool, 2u>;
using bvecd3 = vec<bool, 3u>;
using bvecd4 = vec<bool, 4u>;
} //bvec namespace

/////////////////////////////////////////////////
/// \brief Signed and unsigned integer vectors
/// This name space includes separate classes for signed and unsigned
/// `int`
/// type 2-4 dimensional vectors
/////////////////////////////////////////////////
namespace ivec
{
using ivec2 = vec<int, 2>;
using ivec3 = vec<int, 3>;
using ivec4 = vec<int, 4>;
using uvec2 = vec<unsigned int, 2u>;
using uvec3 = vec<unsigned int, 3u>;
using uvec4 = vec<unsigned int, 4u>;
} //ivec namespace

} //namespace sbt


#endif //vec_HPP_
