ref ZenTreesplosionsConfig g_ZenTreesplosionsConfig;

static ZenTreesplosionsConfig GetZenTreesplosionsConfig()
{
	if (!g_ZenTreesplosionsConfig) GetZenConfigRegister().RegisterConfig(ZenTreesplosionsConfig);
	return g_ZenTreesplosionsConfig;
}

modded class ZenConfigRegister
{
	override void RegisterPreload()
	{
		super.RegisterPreload();
		RegisterType(ZenTreesplosionsConfig);
	}
}

class ZenTreesplosionsConfig: ZenConfigBase
{
	// -------------------------
	// CONFIG SETTINGS
	// -------------------------
	override void OnRegistered()
	{
		g_ZenTreesplosionsConfig = this;
	}
	
	override string    	GetCurrentVersion()   		{ return "1.29.1"; }
	override bool		ShouldLoadOnServer() 		{ return true; }
	override bool 		IsServerOnlyConfig()		{ return true; }
	
	override bool ReadJson(string path, out string err)
	{
		return JsonFileLoader<ZenTreesplosionsConfig>.LoadFile(path, this, err);
	}

	override bool WriteJson(string path, out string err)
	{
		return JsonFileLoader<ZenTreesplosionsConfig>.SaveFile(path, this, err);
	}
	
	// -------------------------
	// CONFIG VARS
	// -------------------------
	ref array<ref TreesplosionType> TreesplosionTypes = new array<ref TreesplosionType>;

	override void SetDefaults()
	{
		TreesplosionTypes.Clear();
		TreesplosionTypes.Insert(new TreesplosionType("M67Grenade", 10, false));
		TreesplosionTypes.Insert(new TreesplosionType("RGD5Grenade", 10, false));
		TreesplosionTypes.Insert(new TreesplosionType("ClaymoreMine", 15));
		TreesplosionTypes.Insert(new TreesplosionType("Zen40mmTreeKiller", 10));
		TreesplosionTypes.Insert(new TreesplosionType("Plastic_Explosive", 15));
		TreesplosionTypes.Insert(new TreesplosionType("ImprovisedExplosive", 15));
	}

	// Get zombie config for given type
	TreesplosionType GetTreesplosionType(string type)
	{
		string explosiveType = type;
		explosiveType.ToLower();

		foreach (TreesplosionType cfg : TreesplosionTypes)
		{
			string toFind = cfg.ExplosiveType;
			toFind.ToLower();
			if (explosiveType.Contains(toFind))
			{
				return cfg;
			}
		}

		return null;
	}
}

// Define a tree explosion type
class TreesplosionType
{
	string ExplosiveType;
	int Radius;
	bool CutTreeSoft = true;
	bool CutTreeHard = true;
	bool CutBushSoft = true;
	bool CutBushHard = true;

	void TreesplosionType(string p_type, int p_radius, bool p_treehard = true)
	{
		ExplosiveType = p_type;
		Radius = p_radius;
		CutTreeHard = p_treehard;
	}
}
