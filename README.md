# unibuild
Universal build system for C and C++.

Uses it's own `unibuild.json` file as a build process description.

During development can be used as a build system on it's own.
When releasing your software, you can convert it to makefiles, cmakelists and build shell scripts, depending on your needs.

### Why?
When releasing our software, it's easy to make it impossible to compile on certain systems via using build systems unavailable on it, additionally using them pretty much locks you in their own ecosystems. Unibuild forces you to think of situations where that may be the case, additionally providing an easy way to mitigate it (via converting to multiple build systems). 
