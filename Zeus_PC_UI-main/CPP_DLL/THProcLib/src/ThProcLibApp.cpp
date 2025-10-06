
#include "ThProcLibMain.h"
#include "ThProcLibMainSys.h"
#ifdef MakeThProcLibDummy
#include "ThProcLibMainDummy.h"
#endif
#include<memory>
std::unique_ptr < CThProcMain> g_ThProcMain;

//#221_added_dll_called_log
std::unique_ptr < UICallLogger> g_UICallLogger; 
#define Trace_Entry_APP  UICallLogger::_TraceLog _enter_log(__FUNCTIONW__,g_UICallLogger.get());

 bool app_getAllLoggerStr(std::wstring &out_str) {
	 if (g_UICallLogger == nullptr) return true;
	return g_UICallLogger->getRecordStr(out_str);
}
bool app_checkCallLoggerDog(void) {
	if (g_UICallLogger == nullptr) return false;
	return g_UICallLogger->checkCallLoggerDog();
}

int th_lib_init(int mode)
{
#ifdef MakeThProcLibDummy
	g_ThProcMain.reset(new CThProcMainDummy);
#else
	g_ThProcMain.reset(new CThProcMainSys);
#endif
	int sts = g_ThProcMain->th_lib_init( mode);
	//#221_added_dll_called_log
	if (g_ThProcMain->get_dll_called_log()) {
		if (g_UICallLogger == nullptr) {//global singleton
			g_UICallLogger.reset(UICallLogger::createLogger());
		}
	}
	return sts;
}
void th_lib_close(void)
{//#183_th_lib_close
	g_ThProcMain.reset();
}
int th_lib_setup_env(const ThProcLib_Env* env)
{
	if (g_ThProcMain==nullptr) return -1;
	Trace_Entry_APP;
	return g_ThProcMain->th_lib_setup_env(env);
}
int th_lib_get_env(ThProcLib_Env* env)
{
	if (g_ThProcMain == nullptr) return -1;
	Trace_Entry_APP;
	return g_ThProcMain->th_lib_get_env(env);
}
int th_lib_get_datalist_size(int type)
{
	if (g_ThProcMain == nullptr) return -1;
	Trace_Entry_APP;
	return g_ThProcMain->th_lib_get_datalist_size(type);
}
int th_lib_get_datalist(ThProcLib_PatientInfo* out_info, int type,int no)
{
	if (g_ThProcMain == nullptr) return -1;
	Trace_Entry_APP;
	return g_ThProcMain->th_lib_get_datalist(out_info,  type,no);
}
int th_lib_exe_cmd(const ThProcLib_Cmd* cmd, ThProcLib_CmdOutput* cmd_ret)
{
	if (g_ThProcMain == nullptr) return -1;
	Trace_Entry_APP;
	return g_ThProcMain->th_lib_exe_cmd(cmd, cmd_ret);
};
int th_lib_get_image_info(const ThProcLib_Cmd* cmd, ThProcLib_DicomImageInfo* image_info)
{
	if (g_ThProcMain == nullptr) return -1;
	Trace_Entry_APP;
	return g_ThProcMain->th_lib_get_image_info(cmd, image_info);
}
int th_lib_get_data(const ThProcLib_Cmd* cmd, unsigned char* DataBuffer, int BufferSize)
{
	if (g_ThProcMain == nullptr) return -1;
	Trace_Entry_APP;
	return g_ThProcMain->th_lib_get_data(cmd, DataBuffer, BufferSize);
}
int th_lib_get_status(int cmdUID, ThProcLib_CmdStatus* status)
{
	if (g_ThProcMain == nullptr) return -1;
	Trace_Entry_APP;
	return g_ThProcMain->th_lib_get_status(cmdUID, status);
}
int th_lib_close_cmd(int cmdUID)
{
	if (g_ThProcMain == nullptr) return -1;
	Trace_Entry_APP;
	return g_ThProcMain->th_lib_close_cmd(cmdUID);
}

int th_lib_get_vol_info(const ThProcLib_Cmd* cmd, ThProcLib_Vol3DData* outVol)
{
	if (g_ThProcMain == nullptr) return -1;
	Trace_Entry_APP;
	return g_ThProcMain->th_lib_get_vol_info(cmd, outVol);
}
///#43_rendering_command
int th_lib_render_GC(const ThProcLib_Cmd* cmd, ThProcLib_RenderGC* outGC)
{
	if (g_ThProcMain == nullptr) return -1;
	Trace_Entry_APP;
	return g_ThProcMain->th_lib_render_GC(cmd, outGC);
}
int th_lib_exe_render(const ThProcLib_Cmd* cmd, const ThProcLib_RenderGC* param, ThProcLib_Image2DData* outImage)
{
	if (g_ThProcMain == nullptr) return -1;
	Trace_Entry_APP;
	return g_ThProcMain->th_lib_exe_render(cmd, param, outImage);
}
