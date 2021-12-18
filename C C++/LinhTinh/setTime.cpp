#include<iostream>
using namespace std;

class Time
{
private:
    int hour;
    int minute;
    int second;
public:
    Time() {}
    Time(int hour, int minute, int second)
    {
        this->hour=hour;
        this->minute=minute;
        this->second=second;
    }
    void setTime(int hour, int minute, int second)
    {
        this->hour=hour;
        this->minute=minute;
        this->second=second;
    }
    int getHour() {return hour;}
    void setHour(int hour) {this->hour=hour;}
    int getMinute() {return minute;}
    void setMinute(int minute) {this->minute=minute;}
    int getSecond() {return second;}
    void setSecond(int second) {this->second=second;}
    void previousSecond()
    {
        if(this->hour==0&&this->minute==0&&this->second==0)
        {
            this->hour=23;
            this->minute=59;
            this->second=59;
            return;
        }
        if(this->minute==0&&this->second==0)
        {
            this->hour--;
            this->minute=59;
            this->second=59;
            return;
        }
        if(this->second==0)
        {
            this->minute--;
            this->second=59;
            return;
        }
        this->second--;
    }
    void nextSecond()
    {
        if(this->hour==23&&this->minute==59&&this->second==59)
        {
            this->hour=0;
            this->minute=0;
            this->second=0;
            return;
        }
        if(this->minute==59&&this->second==59)
        {
            this->hour++;
            this->minute=0;
            this->second=0;
            return;
        }
        if(this->second==59)
        {
            this->minute++;
            this->second=0;
            return;
        }
        this->second++;
    }
    void display()
    {
        string hour=to_string(this->hour);
        string minute=to_string(this->minute);
        string second=to_string(this->second);
        if(hour.length()==1)
            hour="0"+hour;
        if(minute.size()==1)
            minute="0"+minute;
        if(second.length()==1)
            second="0"+second;
        //cout<<this->hour<<":"<<this->minute<<":"<<this->second<<endl;
        cout<<hour<<":"<<minute<<":"<<second<<endl;
    }
};