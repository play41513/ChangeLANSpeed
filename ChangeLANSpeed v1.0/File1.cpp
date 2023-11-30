//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include <tchar.h>
#include <Registry.hpp>
//---------------------------------------------------------------------------

#pragma argsused
int _tmain(int argc, _TCHAR* argv[])
{
	if(argc == 3)
	{
		AnsiString temppath, temp, LANnum;
		TRegistry *reg = new TRegistry();
		TStringList *ts = new TStringList;
		reg->RootKey = HKEY_LOCAL_MACHINE;
		temppath = "SYSTEM\\CurrentControlSet\\Control\\Class\\{4d36e972-e325-11ce-bfc1-08002be10318}";
		reg->OpenKey(temppath.c_str(), false);
		reg->GetKeyNames(ts);
		for (int i = 0; i < ts->Count; i++) {
		//¸ô®|¦WºÙ¸É0
			LANnum = ts->Strings[i];
			temppath = "SYSTEM\\CurrentControlSet\\Control\\Class\\{4d36e972-e325-11ce-bfc1-08002be10318}\\"+ LANnum;
			reg->CloseKey();
			reg->OpenKey(temppath.c_str(), false);
			long tollnum = reg->InstanceSize();
			AnsiString tempDeviceID = (AnsiString)reg->ReadString("DriverDesc");

			if(tempDeviceID.Pos(AnsiString(argv[1])))
			{
				reg->WriteString("*SpeedDuplex", AnsiString(argv[2]).ToInt());
			}
		}
		reg->CloseKey();
		delete reg,ts;
	}
	return 0;
}
//---------------------------------------------------------------------------
