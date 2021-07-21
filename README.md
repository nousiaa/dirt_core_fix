# dirt_core_fix
A fix for dirt rally crashing at startup on some setups (e.g. windows 7 and ryzen 2700x)

The crashes seem to result from an call to GetLogicalProcessorInformation with a buffer size that is too small.

This program modifies the game executable to skip the call to this function, which allows the game to start.

Usage:
compile corepatch.cpp and run the resulting executable from the same directory where drt.exe is.

**Note, the code no longer works, for now, use any hex editor to replace the following hex-values C7 45 F0 00 06 00 00 FF D0 with the following values B8 01 00 00 00 90 90 90 90**
