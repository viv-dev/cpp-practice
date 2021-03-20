# Practice

This is just a small project for me to refresh and experiment with different parts of the C++ language.

It has been broken up into different sub-directories each producing a library with sample code for the topic area.

As of this writing, most of these classes are capturing techniques mentioned in 'Effective C++' (and modernising them, if relevant, through suggestions in 'Modern Effective C++').

## CMake Setup

This project was setup trying to follow modern CMake best practices. More specifically laying out the project heirarchy with subdirectories following the information provided by Craig Scott [here](https://crascit.com/2016/01/31/enhanced-source-file-handling-with-target_sources/).

## Conan

Conan is being used to manage any 3rd party libraries. To ensure these are available please run `conan install .` before attempting to build.

## Testing

Testing is being performed using doctest in the test directory. Testing is the primary way of 'running' the libraries, as they form a good way of both running and validating each of the example exercises.
