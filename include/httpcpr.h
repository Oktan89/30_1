#pragma once
#include <string>
#include <cpr/cpr.h>

namespace httpOk
{
    class Httpcpr
    {
    protected:
        const std::string _url{"http://httpbin.org/"};
        std::string _modifined_url;
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

    public:
        Httpcpr() 
        {
            _modifined_url = _url;
        }
        Httpcpr(const std::string &url)
        {
            setUrl(url);
        }
        void setUrl(const std::string &url)
        {
            _modifined_url += _url + url;
        }
        virtual cpr::Response query() = 0;
        virtual ~Httpcpr() {}
    };

    class Get : public Httpcpr
    {

    public:
        Get() {}
        Get(const std::string &url) : Httpcpr(url) {}
        virtual cpr::Response query()
        {
            return cpr::Get(cpr::Url{_modifined_url}, cpr::ProgressCallback(callback));
        }
        ~Get() {}
    };

    class Post : public Httpcpr
    {

    public:
        Post() {}
        Post(const std::string &url) : Httpcpr(url) {}
        virtual cpr::Response query()
        {
            return cpr::Post(cpr::Url{_modifined_url}, cpr::ProgressCallback(callback));
        }
        ~Post() {}
    };

    class Put : public Httpcpr
    {
    public:
        Put() {}
        Put(const std::string &url) : Httpcpr(url) {}
        virtual cpr::Response query()
        {
            return cpr::Put(cpr::Url{_modifined_url}, cpr::ProgressCallback(callback));
        }
        ~Put() {}
    };

    class Delete : public Httpcpr
    {
    public:
        Delete() {}
        Delete(const std::string &url) : Httpcpr(url) {}
        virtual cpr::Response query()
        {
            return cpr::Delete(cpr::Url{_modifined_url}, cpr::ProgressCallback(callback));
        }
        ~Delete() {}
    };

    class Patch : public Httpcpr
    {
    public:
        Patch() {}
        Patch(const std::string &url) : Httpcpr(url) {}
        virtual cpr::Response query()
        {
            return cpr::Patch(cpr::Url{_modifined_url}, cpr::ProgressCallback(callback));
        }
        ~Patch() {}
    };
}