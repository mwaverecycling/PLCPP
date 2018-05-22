#ifndef PLCVALUECHANGER_HPP
#define PLCVALUECHANGER_HPP

#include <string>
#include <map>
#include <vector>

#include <PLCValues.hpp>
#include <PLCValueListener.hpp>

using namespace std;

class PLCValueChanger
{
    public:
        PLCValueChanger();
        virtual ~PLCValueChanger();
        void addListener(PLCValueListener* listener, string name);
        void removeListener(PLCValueListener* listener);
        void removeListener(PLCValueListener* listener, string name);
        void changeValue(string name, struct PLCValueEvent event);

    private:
        map<string, vector<PLCValueListener *>> listeners;
};

#endif // PLCVALUECHANGER_HPP
