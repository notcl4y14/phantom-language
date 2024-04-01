@echo off
if not exist dist ( mkdir dist )
g++ src/*.c++ main.c++ -o dist\phantom.exe