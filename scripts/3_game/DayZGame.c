modded class DayZGame
{
	#ifdef SERVER 
	//! TREESPLOSIONS
	override void FirearmEffects(Object source, Object directHit, int componentIndex, string surface, vector pos, vector surfNormal, vector exitPos, vector inSpeed, vector outSpeed, bool isWater, bool deflected, string ammoType)
	{
		super.FirearmEffects(source, directHit, componentIndex, surface, pos, surfNormal, exitPos, inSpeed, outSpeed, isWater, deflected, ammoType);

		//! TREESPLOSIONS
		#ifdef ZENMODPACK
		if (!ZenModEnabled("ZenTreesplosions"))
			return;
		#endif

		// If bullet impact detect on server, spawn tree killer entity (scans nearby trees to cut down)
		// Spawn 100m in the air away from explosion, or our "invisible" rock object's hitbox will block damage dispersion (height is adjusted in Zen40mmTreeKiller.c)
		if (ammoType == "Bullet_40mm_Explosive" || ammoType == "ExpansionRocket")
			GetGame().CreateObjectEx("Zen40mmTreeKiller", pos + "0 100 0", ECE_PLACE_ON_SURFACE);
	}
	#endif
}