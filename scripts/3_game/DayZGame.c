modded class DayZGame
{
	override void FirearmEffects(Object source, Object directHit, int componentIndex, string surface, vector pos, vector surfNormal, vector exitPos, vector inSpeed, vector outSpeed, bool isWater, bool deflected, string ammoType)
	{
		super.FirearmEffects(source, directHit, componentIndex, surface, pos, surfNormal, exitPos, inSpeed, outSpeed, isWater, deflected, ammoType);

		// Spawn tree killer
		if (ammoType == "Bullet_40mm_Explosive")
			GetGame().CreateObjectEx("Zen40mmTreeKiller", pos, ECE_PLACE_ON_SURFACE);
	}
};