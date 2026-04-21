/*
	(c) 2026 | ZenTreesplosions | Zenarchist
*/

class CfgPatches
{
	class ZenTreesplosions
	{
		requiredAddons[] = 
		{ 
			"DZ_Data",
			"DZ_Scripts",
			"ZenModCore"
		};
	};
};

class CfgMods
{
	class ZenTreesplosions
	{
		author = "Zenarchist";
		type = "mod";
		defines[] = 
		{
			//"ZENSKILLSDEBUG"
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
	class Inventory_Base;
	
	//! TREESPLOSIONS
	class Zen40mmTreeKiller : Inventory_Base
	{
		scope = 1;
		model = "\dz\gear\consumables\Stone.p3d";
		hiddenSelections[] = { "zbytek" };
		hiddenSelectionsTextures[] = { "#(argb,8,8,3)color(1,1,1,0,CA)" };
	};
};