# Check that people use the good file
if(NOT TOP_CMAKE_WAS_SOURCED)
    message(FATAL_ERROR "
    You did not 'cmake' the good CMakeLists.txt file. Use the one in the top dir.
    It is advice to delete all wrongly generated cmake stuff => CMakeFiles & CMakeCache.txt")
endif()


# plugin name
set(Output FWnull-0.7.0)

set(OptimizationFlags
    -O2
    )

if(CMAKE_BUILD_TYPE STREQUAL Debug)
    set(FWnullFinalFlags "")

elseif(CMAKE_BUILD_TYPE STREQUAL Devel)
	set(FWnullFinalFlags ${OptimizationFlags})

elseif(CMAKE_BUILD_TYPE STREQUAL Release)
	set(FWnullFinalFlags ${OptimizationFlags})

endif()

# FWnull sources
set(FWnullSources
	Config.cpp
	FW.cpp)

# FWnull headers
set(FWnullHeaders
	Config.h
	FW.h)

# FWnull Linux sources
set(FWnullLinuxSources
)

# FWnull Linux headers
set(FWnullLinuxHeaders
)

# FWnull Windows sources
set(FWnullWindowsSources
	Windows/Config.cpp
	Windows/FireWireNull.def
	Windows/FireWireNul.rc
	Windows/Win32.cpp)

# FWnull Windows headers
set(FWnullWindowsHeaders
	Windows/resource.h)

set(FWnullFinalSources
	${FWnullSources}
	${FWnullHeaders}
	${FWnullLinuxSources}
	${FWnullLinuxHeaders}
)

set(FWnullFinalLibs
	${GTK2_LIBRARIES}
)

add_pcsx2_plugin(${Output} "${FWnullFinalSources}" "${FWnullFinalLibs}" "${FWnullFinalFlags}")
