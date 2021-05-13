#include<iostream>
#include<iostream>
#include<ctime>
#include<string>

class timeDate
{

private:
	unsigned int dd;
	unsigned int mm;
	unsigned int yyyy;
	unsigned int _hh;
	unsigned int _mm;
	unsigned int _ss;

public:
	timeDate(void);
	timeDate(unsigned int day, mounth, year, hour, min, sec);
	timeDate(const timeDate& num);
	timeDate(timeDate&& link);

	int getyear() const {
		return yyyy;			
	}

	int getmounth() const {
		return mm;				
	}

	int getday() const {
		return dd;				
	}

	int gethour() const {
		return _hh;				
	}

	int getminute() const {
		return _mm;				
	}

	int getsecond() const {
		return _ss;				
	}

	void setyear(int val) {
		yyyy = val;				
	}

	void setmounth(int val) {
		if (isMounthCorrect(val)) mm = val;		
	}

	void setday(int val) {
		if (isMounthCorrect(val)) dd = val;
	}

	void sethour(int val) {
		if (isMounthCorrect(val)) _hh = val;
	}

	void setminute(int val) {
		if (isMounthCorrect(val)) _mm = val;
	}

	void setsecond(int val) {
		if (isMounthCorrect(val)) _ss = val;
	}

	struct Date {
		unsigned int dd;		
		unsigned int mm;
		unsigned int yyyy;
	};

	Date date();

	struct Time {
		unsigned int _hh;	
		unsigned int _mm;
		unsigned int _ss;
	};

	Time time();

	static bool isDataCorrect(int dd);

	static bool isMounthCorrect(int mm);

	static bool isHourCorrect(int hh);

	static bool isMinuteCorrect(int mm);

	static bool isSecondCorrect(int ss);

	void nowTimeDate();

	std::string dateToString(std::string scape);

	void dateTemplate(std::string scape);

	void dateFromString(std::string date, std::string frm);
};