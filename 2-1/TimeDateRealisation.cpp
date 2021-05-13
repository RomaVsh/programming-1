#define _CRT_SECURE_NO_WARNINGS
#include"timeDate.h"

timeDate::timeDate(void) {
	dd = mm = yyyy = _hh = _mm = _ss = 0; 
}; 

timeDate::timeDate(unsigned int day, unsigned int mounth, unsigned int year, unsigned int hour, unsigned int min, unsigned int sec) : timeDate() {
	setmounth(mounth);		
	setyear(year);			
	setday(day);			
	setminute(min);			
	setsecond(sec);
	sethour(hour);		
};

timeDate::timeDate(const timeDate& num) {
	dd = num.dd;
	mm = num.mm;		
	yyyy = num.yyyy;	
	_hh = num._hh;
	_mm = num._mm;
	_ss = num._ss;
};	

timeDate::timeDate(timeDate&& link) {
	dd = link.dd;
	mm = link.mm;
	yyyy = link.yyyy;
	_hh = link._hh;		
	_mm = link._mm;
	_ss = link._ss;
};

struct timeDate::Date timeDate::date() { 
	struct Date dateFromStruct;			
	dateFromStruct.dd = dd;				
	dateFromStruct.mm = mm;				
	dateFromStruct.yyyy = yyyy;
	return dateFromStruct;				
}

struct timeDate::Time timeDate::time() { 
	struct Time timeFromStruct;			
	timeFromStruct._hh = _hh;
	timeFromStruct._mm = _mm;			
	timeFromStruct._ss = _ss;
	return timeFromStruct;				
}

bool timeDate::isDataCorrect(int dd) { 
	return ((dd >= 1) && (dd <= 31));
};

bool timeDate::isMounthCorrect(int mm) { 
	return ((mm >= 1) && (mm <= 12));
};

bool timeDate::isHourCorrect(int hh) { 
	return ((hh >= 0) && (hh <= 23));
};

bool timeDate::isMinuteCorrect(int mm) { 
	return ((mm >= 0) && (mm <= 59));
};

bool timeDate::isSecondCorrect(int ss) {
	return ((ss >= 0) && (ss <= 59));
};

void timeDate::nowTimeDate() {
	time_t clock;
	tm* nowtime;
	std::time(&clock);

	nowtime = localtime(&clock);
	dd = nowtime->tm_mday;			
	mm = nowtime->tm_mon + 1;
	yyyy = nowtime->tm_year + 1900;	
	_hh = nowtime->tm_hour;
	_mm = nowtime->tm_min;
	_ss = nowtime->tm_sec;
};

std::string timeDate::dateToString(std::string scape) {	

	std::string ret = scape;		

	ret = ret.replace(scape.find("DD"), 2, std::to_string(dd));
	ret = ret.replace(scape.find("YYYY"), 4, std::to_string(yyyy));		
	ret = ret.replace(scape.find("MM"), 2, std::to_string(mm));
	ret = ret.replace(scape.find("hh"), 2, std::to_string(_hh));
	ret = ret.replace(scape.find("mm"), 2, std::to_string(_mm));		
	ret = ret.replace(scape.find("ss"), 2, std::to_string(_ss));
	
	return ret;
}

void timeDate::dateTemplate(std::string scape) {	
	std::cout << dateToString(scape);				
}

void timeDate::dateFromString(std::string date, std::string frm) {
	int d1 = frm.find("DD");							
	int m1 = frm.find("MM");							
	int y1 = frm.find("YYYY");							
	int h1 = frm.find("hh");							
	int m2 = frm.find("mm");							
	int s1 = frm.find("ss");							  

	dd = ((date[d1]) - '0') * 10 + (date[d1 + 1]) - '0';			
	mm = ((date[m1]) - '0') * 10 + (date[m1 + 1]) - '0';
	yyyy = ((date[y1]) - '0') * 1000 + ((date[y1 + 1]) - '0') * 100 + ((date[y1 + 2]) - '0') * 10 + (date[y1 + 3]) - '0';
	_hh = ((date[h1]) - '0') * 10 + (date[h1 + 1]) - '0';			
	_mm = ((date[m2]) - '0') * 10 + (date[m2 + 1]) - '0';
	_ss = ((date[s1]) - '0') * 10 + (date[s1 + 1]) - '0';			
};
