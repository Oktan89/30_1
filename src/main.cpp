#include <iostream>
#include <string>
#include "httpcpr.h"

int main()
{

    httpOk::Httpcpr *get = nullptr;
    std::string answer;

    do
    {
        std::cout << "Enter: get || post || put || delete || patch || exit" << std::endl;
        std::cin >> answer;
        if (answer == "get")
        {
            if (get != nullptr)
                delete get;

            get = new httpOk::Get(answer);
            auto r = get->query();
            std::cout << r.text << std::endl;
            delete get;
            get = nullptr;
        }
        else if (answer == "post")
        {
            if (get != nullptr)
                delete get;

            get = new httpOk::Post(answer);
            auto r = get->query();
            std::cout << r.text << std::endl;
            delete get;
            get = nullptr;
        }
        else if (answer == "put")
        {
            if (get != nullptr)
                delete get;

            get = new httpOk::Put(answer);
            auto r = get->query();
            std::cout << r.text << std::endl;
            delete get;
            get = nullptr;
        }
        else if (answer == "delete")
        {
            if (get != nullptr)
                delete get;

            get = new httpOk::Delete(answer);
            auto r = get->query();
            std::cout << r.text << std::endl;
            delete get;
            get = nullptr;
        }
        else if (answer == "patch")
        {
            if (get != nullptr)
                delete get;

            get = new httpOk::Patch(answer);
            auto r = get->query();
            std::cout << r.text << std::endl;
            delete get;
            get = nullptr;
        }
        else if (answer != "exit")
        {
            if (get != nullptr)
                delete get;

            get = new httpOk::Get(answer);
            auto r = get->query();
            std::cout << r.text << std::endl;
            delete get;
            get = nullptr;
        }

    } while (answer != "exit");

    if (get != nullptr)
        delete get;
    return 0;
}