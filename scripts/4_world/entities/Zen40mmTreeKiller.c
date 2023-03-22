// This "object" is invisible and only exists to explode trees around a 40mm shell
class Zen40mmTreeKiller extends Inventory_Base
{
	void Zen40mmTreeKiller()
	{
		// Set invisible
		SetPilotLight(true);
		SetIsHologram(true);

		// Delete immediately to trigger tree killing
		GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(DeleteSafe, 1, false);
	}

	override void EEDelete(EntityAI parent)
	{
		super.EEDelete(parent);

		if (!GetGame().IsDedicatedServer())
			return;

		// Get explosion type config
		TreesplosionType tt = GetTreesplosionsConfig().GetTreesplosionType("40mm_Explosive");

		// Get objects at position
		array<Object> objectsNearBomb = new array<Object>;
		GetGame().GetObjectsAtPosition(GetPosition(), tt.Radius, objectsNearBomb, null);

		for (int x = 0; x < objectsNearBomb.Count(); x++)
		{
			Object obj = objectsNearBomb[x];
			if ((obj.IsInherited(TreeSoft) && tt.CutTreeSoft) || (obj.IsInherited(BushHard) && tt.CutBushHard) || (obj.IsInherited(BushSoft) && tt.CutBushSoft) || (obj.IsInherited(TreeHard) && tt.CutTreeHard))
			{
				// Kill tree
				obj.SetHealth(0);
				dBodyDestroy(obj);
			}
		};
	}
};