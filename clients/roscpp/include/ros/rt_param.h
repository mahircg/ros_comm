#ifndef ROSCPP_RT_PARAM_H
#define ROSCPP_RT_PARAM_H

namespace ros
{

struct ROSCPP_DECL RtParam
{
public:
	std::string sched_type;
	std::string scheduler;
	int partition;
	int priority;
	int period;
	int budget;

	RtParam()
	: partition(-1)
	, priority(-1)
	, period(-1)
	, budget(-1)
	{}
};
typedef boost::shared_ptr<RtParam> RtParamPtr;

}
#endif
