

typedef enum daysofweek{Sunday = 0, Monday, Tuesday, Wednesday, Thursday, Friday, Saturday};
static const char* const days_names[] = {
	[Sunday] = "Sunday",
	[Monday] = "Monday",
	[Tuesday] = "Tuesday",
	[Wednesday] = "Wednesday",
    [Thursday] = "Thursday",
    [Friday] = "Friday",
    [Saturday] = "Saturday",
};

int check(char* val, int day) {
    if(day > 6 | day < 0)  {
        return 0;
    }
    val = days_names[day];
    return 1;
}

