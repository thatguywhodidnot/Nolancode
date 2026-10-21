Set-Alias ll Get-ChildItem
Set-Alias np notepad.exe
function nolancode {
    cd "C:\Users\nomil\OneDrive\Desktop\Nolancode"
}

function home { cd ~ }

Set-Alias grep Select-String
#Set-Alias cat Get-Content
#Set-Alias pwd Get-Location

function touch {
    New-Item -ItemType File -Path $args
}

function reload {
    . $PROFILE
}

function off {
    shutdown /s /t 0
}

function reboot {
    shutdown /r /t 0
}

function sleep {
    rundll32.exe powrprof.dll,SetSuspendState Sleep
}

function lock {
    rundll32.exe user32.dll,LockWorkStation
}

function raycompile{
	C:\raylib\w64devkit\bin\g++.exe $args -o game.exe -IC:\raylib\raylib\src -LC:\raylib\raylib\src -lraylib -lopengl32 -lgdi32 -lwinmm
}