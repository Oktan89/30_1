#include <iostream>

#include <cpr/cpr.h>
#include "httpcpr.h"

std::function<bool(size_t, size_t, size_t, size_t)> callback = [](size_t downloadTotal, size_t downloadNow, size_t uploadTotal, size_t uploadNow) -> bool
{
    static size_t s_col = 0;
    static size_t s_total = 0;
    if (downloadNow == 0 || downloadNow == s_col)
        return true;

    if (downloadNow < s_col)
    {
        s_col = 0;
        s_total = 0;
    }

    downloadNow -= s_col;
    s_col += downloadNow;

    s_total += downloadNow;

    std::cout << "Downloaded " << downloadNow << " / " << s_total << " bytes." << std::endl;

    return true;
};

int main()
{

cpr::Response r = cpr::Get(cpr::Url{"http://kselax.ru/contacts/"}, cpr::ProgressCallback(callback));//"http://kselax.ru/contacts/"
    std::cout<<r.text<<std::endl;
 r = cpr::Get(cpr::Url{"http://kselax.ru/category/c/"}, cpr::ProgressCallback(callback));
 std::cout<<r.status_line<<std::endl;
    return 0; 
}