# dirt_core_fix
A fix for dirt rally crashing at startup on some setups (e.g. windows 7 and ryzen 2700x)

The crashes seem to result from an call to GetLogicalProcessorInformation with a buffer size that is too small.

This program modifies the game executable to skip the call to this function, which allows the game to start.

Usage:
compile corepatch.cpp and run the resulting executable from the same directory where drt.exe is.