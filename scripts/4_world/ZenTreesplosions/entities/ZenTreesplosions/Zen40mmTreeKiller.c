// This "object" is invisible and only exists to explode trees around a 40mm shell
class Zen40mmTreeKiller extends Inventory_Base
{
	void Zen40mmTreeKiller()
	{
		// Delete immediately to trigger tree killing
		g_Game.GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(DeleteSafe, 1, false);
	}

	override void EEDelete(EntityAI parent)
	{
		super.EEDelete(parent);

		if (!g_Game.IsDedicatedServer())
			return;

		vector ourRealPos = GetPosition();
		ourRealPos[1] = g_Game.SurfaceY(ourRealPos[0], ourRealPos[2]);

		TreeKiller.KillTree(ourRealPos, GetType());
	}
}