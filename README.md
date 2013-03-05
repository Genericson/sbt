Sumbeard's Tools (SBT)
======================

SBT is a collection (well, maybe "collection" is too strong a word at this point)
c++11 headers released as open source (see license in source files).

Current Features
-----------------

### sbt::vec
A general mathematical vector template class. For use with types that 
implement the mathematical operators.

The specific class template aliases for basic primitives in the namespaces:
  - sbt::fvec - float type
  - sbt::dvec - double type
  - sbt::ivec - signed and unsigned int types
  - sbt::bvec - bool type

Headers
--------
### vec.hpp, vec.inl
  - vec.hpp includes the 'vec' class template prototype and 
  - vec.inl is the implementation of the 'vec' class template. The template is 
    over two files only for readabilty. Do not build or link the *.inl

Other Files
------------
### VecTest.cpp
  - Interactively tests vec methods for basic types (see vec aliases in nested 
    namespaces in vec.hpp)

### Doxyfile
  - Configuration for Doxygen
  
