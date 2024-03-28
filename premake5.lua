local solution_name = "pacman_project"
local project_name  = "pacman"

local win_x86 = "win-x86"
local win_x64 = "win-x64"

local cfg_win_deb = "win-debug"
local cfg_win_rel = "win-release"

workspace( solution_name )
    configurations {  }
    platforms { "Win32", "Win64" }

project( project_name )
    -- project deatils
    kind "ConsoleApp"
    language "C++"

    -- proejct files
    files { "pacman/*.hpp", "pacman/*.cpp" }
    files { "sdl/**.h" , "sdl/**.hpp" , "sdl/**.cpp" , "sdl/**.c" }

    filter { "platforms:Win32" }
        targetdir{ "build/" . win_x86 . "/" }
        system "Windows"
        architecture "x86"

    filter { "platforms:Win64" }
        targetdir{ "build/" . win_x64 . "/" }
        system "Windows"
        architecture "x86_64"

    -- debug configs --
    filter( "configurations:" . cfg_win_deb )
        defines { "DEBUG" }
        symbols "On"
        optimize "Off"

    -- release configs --
    filter( "configurations:" . cfg_win_rel )
        defines { "NDEBUG" }
        symbols "Off"
        optimize "Off"
