class CfgPatches
{
	class ZenTreesplosions
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[] = 
		{ 
			"DZ_Data",
			"DZ_Scripts"
		};
	};
};

class CfgMods
{
	class ZenTreesplosions
	{
		dir="ZenTreesplosions";
		picture=""; 
		action="";
		hideName=1;
		hidePicture=1;
		name="ZenTreesplosions";
		credits=""; 
		author="Zenarchist";
		authorID="0";  
		version="1.0";
		extra=0;
		type="mod";
		dependencies[] =
		{
			"Game",
			"World",
			"Mission"
		};
		class defs
		{
			class gameScriptModule
            {
				value = "";
                files[]=
				{
					"ZenTreesplosions/scripts/3_game"
				};
            };
			
			class worldScriptModule
            {
                value="";
                files[]=
				{ 
					"ZenTreesplosions/scripts/4_world" 
				};
            };
			
	        class missionScriptModule
            {
                value="";
                files[]=
				{
					"ZenTreesplosions/scripts/5_mission" 
				};
            };
		}
	};
};

class CfgVehicles
{
};