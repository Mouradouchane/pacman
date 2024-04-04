local solution_name = "pacman_project"
local project_name  = "pacman"

local sdl_headers = "sdl/include/"
local sdl_x86_libs = "sdl/lib/x86/"
local sdl_x64_libs = "sdl/lib/x64/"

local pacman_path = "pacman/"

local x86_build_path = "build/x86/"
local x64_build_path = "build/x64/"

workspace( solution_name )
    configurations { "Debug" , "Release" }
    platforms { "Win32", "Win64" }
    vpaths { ["sdl"] = sdl_headers }

project( project_name )
    -- project deatils
    kind("ConsoleApp")
    language("C++")

    -- virtual paths in project
    vpaths { ["headers"] = "pacman/*.hpp" }
    vpaths { ["sources"] = "pacman/*.cpp" }

    includedirs { sdl_headers }
    
    -- proejct files
    files { "pacman/*.hpp" , "pacman/*.cpp" , sdl_headers }

    -- windows x86 config
    filter { "platforms:Win32" }
        targetdir( x86_build_path )
        system "Windows"
        architecture "x86"
        links { sdl_x86_libs .. "SDL2.lib" }
        links { sdl_x86_libs .. "SDL2_ttf.lib" }

        -- prebuild commands
        prebuildcommands{ 
            "if not exist build ( mkdir build )" ,
            "if not exist build\\x86 ( mkdir build\\x86 )" ,
            --"copy \"sdl\\lib\\x86\\SDL2.dll\" \"build\\x86\\\"" ,
            --"copy \"sdl\\lib\\x86\\SDL2_ttf.dll\" \"build\\x86\\\""
        } 
        
    -- windows x64 config
    filter { "platforms:Win64" }
        targetdir( x64_build_path )
        system "Windows"
        architecture "x86_64"
        links { sdl_x64_libs .. "SDL2.lib" }
        links { sdl_x64_libs .. "SDL2_ttf.lib" }

        -- prebuild commands
        prebuildcommands{ 
            "if not exist build ( mkdir build )" ,
            "if not exist build\\x64 ( mkdir build\\x64 )" ,
            --"copy \"sdl\\lib\\x64\\SDL2.dll\" \"build\\x64\\\"", 
            --"copy \"sdl\\lib\\x64\\SDL2_ttf.dll\" \"build\\x64\\\""
        } 
        
    -- debug configs --
    filter( "configurations:Debug" )
        defines { "DEBUG" }
        symbols "On"
        optimize "Off"

    -- release configs --
    filter( "configurations:Release" )
        defines { "NDEBUG" }
        symbols "Off"
        optimize "Off"


