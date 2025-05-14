/*
	******************************************************
	*  Author: Th3Spl                                    *
	*  Lang: C++ | Usable in C as well                   *
	*  Date: 27/12/2023                                  * 
	*  Purpose: IoCreateDriver Implementation Example    *
	******************************************************
*/


//
// Inclusions
//
#include <ntifs.h>

// Include CreateDriver header
#include "IoCreateDriver/CreateDriver.h"


//
// Our custom entry point in which our DriverObject field will be a valid pointer
// 
NTSTATUS CustomDriverEntry( _In_ PDRIVER_OBJECT DriverObject, _In_ PUNICODE_STRING RegistryPath )
{
	// Unreferenced parameter
	UNREFERENCED_PARAMETER( RegistryPath );


	//
	// Showing in DebugView the DriverObject's ptr which now will be valid
	//
	DbgPrintEx( 0, 0, "[+] DriverObject: %p", DriverObject );


	//
	// Returning normally
	//  
	return STATUS_SUCCESS;
}


//
// Real entry point
// 
// - Assuming that we're manual mapping the DriverObject field will be invalid
// therefore we're gonna use IoCreateDriver implementation to get a valid DriverObject
// 
// REMEMBER: 
// if you're manual mapping:
//		- Go in C/C++ in settings and disable "Security Check"
//		- Go in linker and set the entry point to "DriverEntry"
//
NTSTATUS DriverEntry( _In_ PDRIVER_OBJECT DriverObject, _In_ PUNICODE_STRING RegistryPath )
{
	// Unreferenced parameters (Both invalid because we're manual mapping)
	UNREFERENCED_PARAMETER( DriverObject );
	UNREFERENCED_PARAMETER( RegistryPath );


	//
	// Now we just have to pass the custom entry point as parameter so that the IoCreateDriver function 
	// can provide a valid DriverObject pointer
	//
	return IoCreateDriver( CustomDriverEntry );
}
