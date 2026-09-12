class Date {
    private int day;
    private int month;
    private int year;
    private int daysInMonth;

    public void setDay(int dd) {
        if (dd < 1 || dd > 31)
            day = 1;
        else
            day = dd;
    }

    public void setDate(int dd, int mm, int yy) {
        year = yy;

        if (mm < 1 || mm > 12)
            month = 1;
        else
            month = mm;

        if (month == 1 || month == 3 || month == 5 || month == 7 ||
            month == 8 || month == 10 || month == 12) {

            if (dd < 1 || dd > 31)
                day = 1;
            else
                day = dd;

        } else if (month == 4 || month == 6 || month == 9 || month == 11) {

            if (dd < 1 || dd > 30)
                day = 1;
            else
                day = dd;

        } else {

            boolean leap = (year % 400 == 0) ||
                           (year % 4 == 0 && year % 100 != 0);

            if (leap) {
                if (dd < 1 || dd > 29)
                    day = 1;
                else
                    day = dd;
            } else {
                if (dd < 1 || dd > 28)
                    day = 1;
                else
                    day = dd;
            }
        }
    }

    public void addDays(int Days) {
        day = day + Days;

        while (true) {

            if (month == 1 || month == 3 || month == 5 || month == 7 ||
                month == 8 || month == 10 || month == 12) {

                daysInMonth = 31;

            } else if (month == 4 || month == 6 || month == 9 || month == 11) {

                daysInMonth = 30;

            } else {

                boolean leap = (year % 400 == 0) ||
                               (year % 4 == 0 && year % 100 != 0);

                if (leap)
                    daysInMonth = 29;
                else
                    daysInMonth = 28;
            }

            if (day <= daysInMonth)
                break;

            day = day - daysInMonth;
            month++; if (month > 12) { month = 1; year++; 
            } } }
    
    public void addMonths(int months) {
        int totalMonths = month - 1 + months;

        year = year + totalMonths / 12;
        month = totalMonths % 12 + 1;

        if (month == 1 || month == 3 || month == 5 || month == 7 ||
            month == 8 || month == 10 || month == 12) {

            daysInMonth = 31;

        } else if (month == 4 || month == 6 || month == 9 || month == 11) {

            daysInMonth = 30;

        } else {

            boolean leap = (year % 400 == 0) ||
                           (year % 4 == 0 && year % 100 != 0);

            if (leap)
                daysInMonth = 29;
            else
                daysInMonth = 28;
        }

        if (day > daysInMonth)
            day = daysInMonth;
    }
    
    public void addYears(int years) {
        year = year + years;

        if (month == 2 && day == 29) {

            boolean leap = (year % 400 == 0) ||
                           (year % 4 == 0 && year % 100 != 0);

            if (!leap)
                day = 28;
        }
    }

public void display() 
{ System.out.println(day + "/" + month + "/" + year); 
} } 