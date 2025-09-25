#ifndef TH_PROC_LIB_LOGGER_H
#define TH_PROC_LIB_LOGGER_H
#include <string>
 
class CThProcLogger
{
public:
	class _TraceLog {
	public:
		_TraceLog(const std::string& str, CThProcLogger* owner,bool enable );
		virtual ~_TraceLog(void);
		CThProcLogger* m_owner;
		std::wstring m_str;
		bool m_enable;
	};
	 
	virtual void LogMessage(const wchar_t* fmt, ...) const =0;
	 
};
 
#endif //LOGGER