modded class ExplosivesBase
{
	override void OnExplode()
	{
		super.OnExplode();

		#ifdef SERVER
		//! TREESPLOSIONS
		#ifdef ZENMODPACK
		if (!ZenModEnabled("ZenTreesplosions"))
			return;
		#endif

		TreeKiller.KillTree(GetPosition(), GetType());
		#endif
	}
}