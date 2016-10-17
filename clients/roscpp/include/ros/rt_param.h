#ifndef ROSCPP_RT_PARAM_H
#define ROSCPP_RT_PARAM_H

#include <litmus.h>


namespace ros
{





struct {
	std::string name;
	std::string abbrev;
	reservation_type_t res_type;
} supported_reservations[] =
{
	{"polling-periodic", "PP", PERIODIC_POLLING},
	{"polling-sporadic", "PS", SPORADIC_POLLING},
	{"soft-polling", "SOFT", SOFT_POLLING},
	{"table-driven", "TD", TABLE_DRIVEN},
	{"constant-bandwidth-server", "CBS", CONSTANT_BANDWIDTH_SERVER},
	{"hard-constant-bandwidth-server", "HCBS", HARD_CONSTANT_BANDWIDTH_SERVER},
	{"deferrable-server", "DS", DEFERRABLE_SERVER},
	{"sporadic-server", "SPS", SPORADIC_SERVER},
	{"capacity-sharing-cbs", "CASH", CASH_CBS},
	{"flexible-cbs", "FCBS", FLEXIBLE_CBS},
	{"slack-donation-capacity-sharing-server", "SLASH", SLASH_SERVER},
	{"semi-partitioned", "SEMI", SEMI_PARTITIONED},
	{"", "", reservation_type_t(0)}
};

static int parse_reservation_type(const std::string &arg)
{
	for (int i = 0; supported_reservations[i].name != ""; i++) {
		if (arg == supported_reservations[i].name ||
		    arg == supported_reservations[i].abbrev)
			return supported_reservations[i].res_type;
	}
	return -1;
}

struct ROSCPP_DECL RtParam
{
public:
	std::string sched_type;
	std::string scheduler;
	reservation_type_t res_type;
	int partition;
	unsigned int priority;
	int period;
	double budget;
	double deadline;
	double offset;
	int res_id;
	bool create_new;

	RtParam()
	: partition(-1)
	, priority(LITMUS_NO_PRIORITY)
	, period(0)
	, budget(0)
  , deadline(0)
	, offset(0)
	, res_id()
	, create_new(false)
	{}

	friend std::ostream& operator<<(std::ostream &os, const RtParam &rt_param);
	const char* to_str(void) {
		std::ostringstream stream;
		stream << *this;
		return stream.str().c_str();

	}
};

std::ostream& operator<<(std::ostream &os, const RtParam &rt_param) {
	os << "sched_type: \t" << rt_param.sched_type << std::endl
		<< "scheduler: \t" << rt_param.scheduler << std::endl
		<< "res_id: \t" << rt_param.res_id << std::endl
		<< "partition: \t" << rt_param.partition << std::endl
		<< "priority: \t" << rt_param.priority << std::endl
		<< "period: \t" << rt_param.period << std::endl
		<< "budget: \t" << rt_param.budget << std::endl
		<< "deadline \t" << rt_param.deadline << std::endl
		<< "offset: \t" << rt_param.offset << std::endl
		<< "create_new \t" << rt_param.create_new << std::endl;
		return os;
}
typedef boost::shared_ptr<RtParam> RtParamPtr;

}
#endif
