@echo off
if not exist dist ( mkdir dist )
g++ src/*.c++ src/utils/*.c++ main.c++ -o dist\phantom.exe %*