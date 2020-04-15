// dllmain.h : Declaration of module class.

class CJCompModule : public CAtlDllModuleT< CJCompModule >
{
public :
	DECLARE_LIBID(LIBID_JCompLib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_JCOMP, "{BA0357A2-353D-48D0-A4E8-730659107A1B}")
};

extern class CJCompModule _AtlModule;
