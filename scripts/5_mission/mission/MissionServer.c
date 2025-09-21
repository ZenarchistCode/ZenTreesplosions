modded class MissionServer
{
	override void OnInit()
	{
		super.OnInit();

		#ifdef ZENMODPACK
		if (!ZenModEnabled("ZenTreesplosions"))
			return;
		#endif

		// Load config
		GetTreesplosionsConfig();
	}
}