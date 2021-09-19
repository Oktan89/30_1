#include <iostream>
#include <cpr/cpr.h>

int main()
{
    cpr::Url url = "http://httpbin.org/get";   
    cpr::Response r = cpr::Get(url);
    std::cout << r.text << std::endl;
    return 0;
}