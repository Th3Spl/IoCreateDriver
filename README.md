# IoCreateDriver

I am just sharing an implementation of IoCreateDriver (which can be found in ntoskrnl.exe)
it doesn't log the driver within `PsLoadedModuleList` and it bypasses `EtwTiLogDriverObjectLoad`
<br />
### Build example:
Within the repository is preset an example that must be compiled using VisualStudio in combination
<br />
with the WDK provided by microsoft.
<br />
### If you're manual mapping:
Remember that if you're manual mapping:
 - You must turn off the security check in `ProjectSettings -> C/C++ -> Security Check`
 - You also have to change the entry point from `FxDriverEntry` to `DriverEntry`
<br />
 - Th3Spl
