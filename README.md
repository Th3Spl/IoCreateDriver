# IoCreateDriver

I am just sharing an implementation of IoCreateDriver (which can be found in ntoskrnl.exe)
it doesn't log the driver within `PsLoadedModuleList` and it bypasses `EtwTiLogDriverObjectLoad`
<br />
### Build example:
Within the repository is preset an example that must be compiled using VisualStudio in combination
<br />
with the WDK provided by microsoft.
<br />
<br />
Enjoy!

- Th3Spl
