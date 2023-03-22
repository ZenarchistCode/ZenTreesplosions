modded class ExplosivesBase
{
	override void OnExplode()
	{
		super.OnExplode();

		if (!GetGame().IsDedicatedServer())
			return;

		// Get explosion type config
		TreesplosionType tt = GetTreesplosionsConfig().GetTreesplosionType(GetType());

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
