#include <iostream>

#include <cpr/cpr.h>


std::function<bool (size_t, size_t, size_t, size_t)> callback = [](size_t downloadTotal, size_t downloadNow, size_t uploadTotal, size_t uploadNow) -> bool
    {
        //static size_t col = 0;
        if(downloadNow > 0)
        {
            std::cout << "Downloaded " << downloadNow << " / " << downloadTotal << " bytes." << std::endl;
        }
        else
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(10));
        }
        
        //system("clear");
        return true;
    };

int main()
{

cpr::Response r = cpr::Get(cpr::Url{"http://kselax.ru/contacts/"}, cpr::ProgressCallback(callback));
    std::cout<<r.downloaded_bytes<<std::endl;
    return 0; 
}