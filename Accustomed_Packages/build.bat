@echo off 
echo Building pak...
u4pak.exe pack pakchunk65-WindowsNoEditor.pak PortalWars
u4pak.exe list pakchunk65-WindowsNoEditor.pak
u4pak.exe info pakchunk65-WindowsNoEditor.pak
u4pak.exe check pakchunk65-WindowsNoEditor.pak
echo Built pak!
pause >nul